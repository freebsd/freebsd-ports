PORTNAME=	ripes
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.4
CATEGORIES=	emulators

MAINTAINER=	mclay@astate.edu
COMMENT=	Graphical processor simulator and assembly editor for the RISC-V ISA

LICENSE=	MIT

USES=		cmake qmake qt:5

USE_QT=		buildtools_build charts concurrent core gui svg testlib widgets

CMAKE_INSTALL_PREFIX=   ${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	mortbopet
GH_PROJECT=	Ripes
GH_TUPLE=	mortbopet:VSRTL:83ee187:VSRTL/external/VSRTL \
		serge1:ELFIO:79fcd11:ELFIO/external/ELFIO \
		mortbopet:libelfin:49d1653:libelfin/external/libelfin \
		yhirose:cpp-mmaplib:c517af7:cpp_mmaplib/external/libelfin/external/cpp-mmaplib \
		pbhogan:Signals:17881fb:Signals/external/VSRTL/external/Signals \
		USCiLab:cereal:51cbda5:cereal/external/VSRTL/external/cereal \
		mortbopet:better-enums:52a694b:better_enums/external/VSRTL/external/better-enums

PORTSCOUT=	ignore:continuous-master

.include <bsd.port.mk>

