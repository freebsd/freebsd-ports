# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	migrate
PORTVERSION=	3.6.11
CATEGORIES=	biology
MASTER_SITES=	http://popgen.sc.fsu.edu/currentversions/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to estimate population sizes and migration rates

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_GMAKE="${MAKE}"
MAKE_ARGS=	PRETTYCFLAGS="${CFLAGS} -DNOJPEG -DNOZLIB -DNOPNG -Iharu \
		-DPRETTY -lstdc++"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PLIST_SUB+=	PORTNAME=${PORTNAME}
PORTDOCS=	HISTORY README README_PARALLEL_GENERAL ${PORTNAME}.html
PORTEXAMPLES=	*
EXTRACT_AFTER_ARGS=--exclude zlib

ALL_TARGET=	all

OPTIONS_DEFINE=			DOCS EXAMPLES THREAD_PRETTY PRETTY THREAD
THREAD_PRETTY_DESC=		Build with THREAD_PRETTY support
THREAD_DESC=			Build with THREAD support
PRETTY_DESC=			Build with PRETTY support
THREAD_PRETTY_ALL_TARGET=	thread-pretty
THREAD_ALL_TARGET=		thread
PRETTY_ALL_TARGET=		pretty

post-patch:
	@${REINPLACE_CMD} -e 's|="-O "|="$$CFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/PRETTY$$/d' ${WRKSRC}/definitions.h
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/haru/makefile.gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-n ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PORTNAME}-n ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	${LN} -sf ${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}-n.1

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/graphics
	${INSTALL_DATA} ${WRKSRC}/../graphics/* ${STAGEDIR}${DOCSDIR}/graphics

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/../example/[A-Za-z]* \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
