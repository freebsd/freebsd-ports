PORTNAME=	f3d
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and minimalist 3D viewer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libvtkCommonMisc-9.1.so:math/vtk9

USES=		cmake compiler:c++11-lang desktop-file-utils gl tar:bzip2 xorg
USE_GL=		gl glu
USE_XORG=	ice sm x11 xt

USE_GITHUB=	yes
GH_ACCOUNT=	f3d-app

PLIST_FILES=	bin/f3d \
		lib/libf3d.so \
		share/applications/f3d.desktop \
		share/bash-completion/completions/f3d \
		share/fish/vendor_completions.d/f3d.fish \
		share/icons/hicolor/32x32/apps/f3d.png \
		share/icons/hicolor/48x48/apps/f3d.png \
		share/icons/hicolor/64x64/apps/f3d.png \
		share/icons/hicolor/scalable/apps/f3d.svg \
		share/metainfo/io.github.f3d_app.f3d.metainfo.xml \
		share/zsh/site-functions/_f3d

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} LICENSE README.md

.include <bsd.port.mk>
