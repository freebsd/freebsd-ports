PORTNAME=	ripes
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	emulators

MAINTAINER=	mclay@astate.edu
COMMENT=	Graphical processor simulator and assembly editor for the RISC-V ISA
WWW=		https://github.com/mortbopet/ripes

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/cereal/cereal.hpp:devel/cereal

USES=		cmake gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	mortbopet
GH_PROJECT=	Ripes
GH_TUPLE=	mortbopet:VSRTL:8497dd1:vsrtl/external/VSRTL \
		mortbopet:libelfin:c06ecb0:libelfin/external/libelfin \
		yhirose:cpp-mmaplib:8cc8551:mmaplib/external/libelfin/external/cpp-mmaplib \
		USCiLab:cereal:22a1b36:cereal \
		serge1:ELFIO:79fcd11:elfio \
		pbhogan:Signals:17881fb:signals \
		Neargye:magic_enum:7f7c704:magic_enum
USE_GL=		gl opengl
USE_QT=		base charts svg

CMAKE_ARGS+=	-DFETCHCONTENT_SOURCE_DIR_CEREAL=${WRKSRC_cereal} \
		-DFETCHCONTENT_SOURCE_DIR_ELFIO=${WRKSRC_elfio} \
		-DFETCHCONTENT_SOURCE_DIR_LIBELFIN=${WRKSRC}/external/libelfin \
		-DFETCHCONTENT_SOURCE_DIR_MAGIC-ENUM=${WRKSRC_magic_enum} \
		-DFETCHCONTENT_SOURCE_DIR_SIGNALS=${WRKSRC_signals}

CMAKE_INSTALL_PREFIX=	${STAGEDIR}${PREFIX}

PORTSCOUT=	limit:^v?[0-9]

.include <bsd.port.mk>
