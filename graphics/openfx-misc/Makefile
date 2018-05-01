# $FreeBSD$

PORTNAME=	openfx-misc
PORTVERSION=	2.3.10
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Miscellaneous OpenFX Effects plugins

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	devernay
GH_PROJECT=	openfx-misc
GH_TAGNAME=	3ab0531
GH_TUPLE=	devernay:openfx-supportext:2c43fc8:openfx_supportext/SupportExt \
		devernay:openfx:e98216f:openfx/openfx

MAKE_ENV+=	CONFIG=release
USE_GL=	gl

pre-patch:
	@${RM} ${WRKSRC}/CImg/CImg.h.orig

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/OFX/Plugins|${PREFIX}/OFX/Plugins|g' \
		${WRKSRC}/openfx/Examples/Makefile.master \
		${WRKSRC}/openfx/Support/Plugins/Makefile.master \
		${WRKSRC}/DebugProxy/DebugProxy.cpp \
		${WRKSRC}/openfx/HostSupport/src/ofxhPluginCache.cpp
		@${REINPLACE_CMD} -e 's|/Contents/$$(ARCH)|/Contents/FreeBSD-x86-64/|g' \
			${WRKSRC}/openfx/Support/Plugins/Makefile.master

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/OFX/Plugins/CImg.ofx.bundle/Contents/FreeBSD-x86-64/CImg.ofx
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/OFX/Plugins/Misc.ofx.bundle/Contents/FreeBSD-x86-64/Misc.ofx
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/OFX/Plugins/Shadertoy.ofx.bundle/Contents/FreeBSD-x86-64/Shadertoy.ofx

.include <bsd.port.mk>
