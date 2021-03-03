# $FreeBSD$

PORTNAME=	re3
DISTVERSION=	g20210219
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Reverse-engineered GTA3 engine

BUILD_DEPENDS=	premake5:devel/premake5
LIB_DEPENDS=	libglfw.so:graphics/glfw \
		libmpg123.so:audio/mpg123 \
		libsndfile.so:audio/libsndfile \
		libsysinfo.so:devel/libsysinfo

USES=		gl gmake openal shebangfix xorg
SHEBANG_FILES=	printHash.sh
USE_GL=		gl
USE_GITHUB=	nodefault
GH_TUPLE=	aap:librw:8b2caf8f:librw \
		xiph:ogg:684c7377:ogg \
		xiph:opus:6bae366f:opus \
		xiph:opusfile:6452e838:opusfile
USE_GITLAB=	yes
GL_SITE=	https://git.rip
GL_ACCOUNT=	Obama
GL_COMMIT=	9a7fa478578beaba947ea867c15a25e411d641d8
bash_CMD=	/bin/sh
USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
SUB_FILES=	${PORTNAME}

post-extract:
	${MV} ${WRKSRC_librw}/* ${WRKSRC}/vendor/librw
	${MV} ${WRKSRC_ogg}/* ${WRKSRC}/vendor/ogg
	${MV} ${WRKSRC_opus}/* ${WRKSRC}/vendor/opus
	${MV} ${WRKSRC_opusfile}/* ${WRKSRC}/vendor/opusfile

do-configure:
	cd ${WRKSRC} && premake5 --with-librw gmake2

do-build:
	cd ${WRKSRC}/build && ${MAKE_ENV} ${MAKE_CMD} config=release_bsd-${ARCH:S/i386/x86/:C/armv.*/arm/:S/aarch64/arm64/}-librw_gl3_glfw-oal

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/re3 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bsd-${ARCH:S/i386/x86/:C/armv.*/arm/:S/aarch64/arm64/}-librw_gl3_glfw-oal/Release/re3 ${STAGEDIR}${DATADIR}/
	(cd ${WRKSRC}/gamefiles && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/)

.include <bsd.port.mk>
