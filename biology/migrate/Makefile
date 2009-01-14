# New ports collection makefile for:	migrate
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	migrate
PORTVERSION=	3.0.3
CATEGORIES=	biology
MASTER_SITES=	http://people.scs.fsu.edu/~beerli/popgen/currentversion/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to estimate population sizes and migration rates

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_GMAKE="${MAKE}"
MAKE_ARGS=	PRETTYCFLAGS="${CFLAGS} -DNOJPEG -DNOZLIB -DNOPNG -Iharu -DPRETTY"

MAN1=		migrate.1
MLINKS=		migrate.1 migrate-n.1

.include <bsd.port.pre.mk>

NOT_FOR_ARCHS=	alpha
ONLY_FOR_ARCHS_REASON=	Does not compile

.if defined(WITH_THREAD_PRETTY)
ALL_TARGET=	thread-pretty
.elif defined(WITH_PRETTY)
ALL_TARGET=	pretty
.elif defined(WITH_THREAD)
ALL_TARGET=	thread
.else
ALL_TARGET=	all
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|="-O "|="$$CFLAGS"|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/migrate-n ${PREFIX}/bin
	${LN} -sf migrate-n ${PREFIX}/bin/migrate
	${INSTALL_MAN} ${WRKSRC}/migrate.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in HISTORY HOWTO-PARALLEL README migrate.html
	${INSTALL_DATA} ${WRKSRC}/../${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/graphics
	${INSTALL_DATA} ${WRKSRC}/../graphics/* ${DOCSDIR}/graphics
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/../example/[A-Za-z]* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
