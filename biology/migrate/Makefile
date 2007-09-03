# New ports collection makefile for:	migrate
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	migrate
PORTVERSION=	2.3
CATEGORIES=	biology
MASTER_SITES=	http://popgen.csit.fsu.edu/currentversion/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to estimate population sizes and migration rates

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
MAKE_ARGS=	HARDWARECFLAGS="${CFLAGS}" \
		MYCPPFLAGS="${CFLAGS} -DNOJPEG -DNOPNG -DNOZLIB"

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
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@CFLAGS@||g ; \
		 s|make -f|$$(MAKE) -f|g' ${WRKSRC}/Makefile.in

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
	${INSTALL_DATA} ${WRKSRC}/../example/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
