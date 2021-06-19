# Created by: Igor Pokrovsky <tiamat@comset.net>

PORTNAME=	openrm
PORTVERSION=	1.6.0.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION:R} \
		SF/${PORTNAME}/${PORTNAME}-demo/${PORTVERSION:R}:demo
DISTNAME=	${PORTNAME}-devel-${PORTVERSION:R}-${PORTVERSION:E}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DEMO_DISTFILE:S/$/:demo/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Development environment used to build 2D/3D/stereo graphics

LICENSE=	LGPL20+  # from sources, though LICENSE file is LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.html

USES=		gl jpeg perl5 shebangfix xorg
SHEBANG_FILES=	doc/*.pl
USE_GL=		glu
USE_XORG=	xmu
USE_PERL5=	build
ALL_TARGET=	freebsd docs
MAKE_ARGS=	AR="${AR}" \
		CC="${CC}" \
		CP="${CP}" \
		ECHO_CMD="${ECHO_CMD}" \
		LN="${LN}" \
		RM="${RM}" \
		STRIP_CMD="${STRIP_CMD}" \
		X11BASE="${LOCALBASE}"
WRKSRC=		${WRKDIR}/rm${PORTVERSION:R:S/.//g}
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-fPIC -DPIC

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
DEMO_DISTFILE=	${DISTNAME:S,-devel-,-demo-,}${EXTRACT_SUFX}
DEMO_WRKSRC=	${WRKDIR}/rmdemo
.endif

post-patch-EXAMPLES-on:
	@${REINPLACE_CMD} -e \
		'/^RM/s|/usr|${PREFIX}| ; \
		 /^OPENGL/s|/usr|${LOCALBASE}| ; \
		 /^X11/s|/usr/X11R6|${LOCALBASE}| ; \
		 /^OPT/s|-g|| ; \
		 /^ARCH/s|-m32|| ; \
		 /^JPEG/s|/usr|${LOCALBASE}|' ${DEMO_WRKSRC}/makeinclude

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/rm
	${INSTALL_DATA} ${WRKSRC}/include/rm/*.h ${STAGEDIR}${PREFIX}/include/rm
.for f in librm librmaux librmi librmv
	${INSTALL_DATA} ${WRKSRC}/lib/${f}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/${f}.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -fs ${f}.so.1 ${STAGEDIR}${PREFIX}/lib/${f}.so
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/HTML/images
	(cd ${WRKSRC} && ${INSTALL_DATA} FUTUREPLANS README RELEASENOTES \
		${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/*.html ${STAGEDIR}${DOCSDIR}/HTML
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/images/* \
		${STAGEDIR}${DOCSDIR}/HTML/images

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/data
	(cd ${DEMO_WRKSRC} && ${INSTALL_DATA} README configure makeinclude \
		Makefile.x11 *.c *.h ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${DEMO_WRKSRC}/data/* ${STAGEDIR}${EXAMPLESDIR}/data

.include <bsd.port.mk>
