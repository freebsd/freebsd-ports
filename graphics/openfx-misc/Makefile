PORTNAME=	openfx-misc
PORTVERSION=	2.4.3
DISTVERSIONPREFIX=	Natron-
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Miscellaneous OpenFX Effects plugins

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

USES=		gl gmake
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_TUPLE=	NatronGitHub:openfx-supportext:79d8c22:openfx_supportext/SupportExt \
		NatronGitHub:openfx:d5db5d0:openfx/openfx \
		dtschump:CImg:b33dcc8f9f1acf1f276ded92c04f8231f6c23fcd:CImg

MAKE_ENV+=	CONFIG=release

post-extract:
	${CP} ${WRKSRC_CImg}/CImg.h ${WRKSRC}/CImg/CImg.h
	${CP} ${WRKSRC_CImg}/plugins/inpaint.h ${WRKSRC}/CImg/Inpaint/inpaint.h

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
