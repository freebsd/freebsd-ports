PORTNAME=	libopendrive
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, lightweight C++ library for handling OpenDRIVE files
WWW=		https://github.com/pageldev/libOpenDRIVE

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	catch2>=3.4.0:devel/catch2 \
		pugixml>=1.14:textproc/pugixml
LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++17-lang

CMAKE_ON=	BUILD_SHARED_LIBS

USE_GITHUB=	yes
GH_ACCOUNT=	pageldev
GH_PROJECT=	libOpenDRIVE
GH_TAGNAME=	82c2dd9

post-patch:
	@${MKDIR} ${WRKSRC}/pugixml/
	@${LN} -s ${LOCALBASE}/include/pugixml.hpp ${WRKSRC}/pugixml/pugixml.hpp
	@${LN} -s ${LOCALBASE}/include/pugiconfig.hpp ${WRKSRC}/pugixml/pugiconfig.hpp

.include <bsd.port.mk>
