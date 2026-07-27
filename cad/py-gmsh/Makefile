PORTNAME=	gmsh
DISTVERSION=	5.0.0-git
CATEGORIES=	cad python
MASTER_SITES=	LOCAL/thierry
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-master-${GL_TAGNAME}
DIST_SUBDIR=	gmsh

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic 3D finite element mesh generator (gmsh's own binding)
WWW=		https://gmsh.info/

LICENSE=	AGPLv3+ APACHE20 GPLv3+ GPLv2+ LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libmmg.so:science/mmg \
		libmesquite.so:math/mesquite \
		libcgns.so:science/cgnslib \
		libfltk_images.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libhdf5.so:science/hdf5 \
		libmedC.so:french/med \
		libpng16.so:graphics/png \
		libsz.so:science/libaec \
		libTKV3d.so:cad/opencascade

USES=		cmake gl gnome jpeg python tar:tgz xorg
USE_PYTHON=	flavors
USE_GNOME=	cairo
USE_GL=		gl glu
USE_XORG=	ice sm x11 xcursor xext xfixes xft xinerama xrender
USE_LDCONFIG=	${PYTHON_SITELIBDIR}

# Pre-release, temporarily used to support OCCT-8
#USE_GITLAB=	yes
#GL_SITE=	https://gitlab.onelab.info/gmsh/gmsh
GL_TAGNAME=	23c47b0e6a91f2f67afcbe3bf9ad1b5c253e96e2
WRKSRC=		${WRKDIR}/gmsh-master

PATCHDIR=	${PORTSDIR}/cad/gmsh/files

CMAKE_ON=	ENABLE_WRAP_PYTHON ENABLE_PRIVATE_API ENABLE_OCC
CMAKE_ARGS=	-DOCC_INC=${LOCALBASE}/include/OpenCASCADE \
		-DGMSHPY_INSTALL_DIRECTORY=${PYTHON_SITELIBDIR}/gmshpy

CXXFLAGS_powerpc64=	-mvsx

post-install: # remove all except for the python binding
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} -r \
			bin/* \
			include/gmsh* \
			lib/gmsh.jl \
			share/doc/gmsh \
			share/man/man1/gmsh.1
	# remove cmake files already installed by GMSH
	@${RM} -rf ${STAGEDIR}${DATADIR}
	# move "private API" libs to the python folder
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	@cd ${STAGEDIR} && \
		${MV} \
			${STAGEDIR}${PREFIX}/lib/gmsh* \
			${STAGEDIR}${PREFIX}/lib/lib* \
			${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
