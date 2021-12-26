PORTNAME=	inscore
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Environment for the design of interactive augmented music scores

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/src/license.txt

LIB_DEPENDS=	libGUIDOEngine.so:audio/guidolib \
		libguidoar.so:audio/guidoar \
		libmicrohttpd.so:www/libmicrohttpd

USES=		cmake gnome qt:5
USE_QT=		core declarative gui network multimedia opengl printsupport sensors svg widgets websockets \
		qmake_build buildtools_build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TAGNAME=	v${PORTVERSION:S/.//}
GH_TUPLE=	grame-cncm:guidolib:3cf3d88:guidolib/modules/guidolib # this uses some un-installed parts of the guidolib project, partucularly QGuidoPainter.h

CMAKE_SOURCE_PATH=	${WRKSRC}/build
CMAKE_ARGS=	-DFREEBSD_EXAMPLESDIR=${EXAMPLESDIR} -DFREEBSD_DOCSDIR=${DOCSDIR}

CXXFLAGS+=	-I${LOCALBASE}/include/guido -I${LOCALBASE}/include/guidoar
CXXFLAGS_powerpc64=	-DOSC_HOST_BIG_ENDIAN
CXXFLAGS_powerpc=	-DOSC_HOST_BIG_ENDIAN

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.mk>
