PORTNAME=	OSKAR
DISTVERSION=	2.13.0
CATEGORIES=	astro

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SKA Radio telescope simulator
WWW=		https://github.com/OxfordSKA/OSKAR/ \
		https://ska-telescope.gitlab.io/sim/oskar/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libhdf5.so:science/hdf5 \
		libsz.so:science/libaec

USES=		cmake compiler:c++11-lang gl localbase:ldflags python qt:6
USE_QT=		base tools:build
USE_GL=		gl opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OxfordSKA

CMAKE_ARGS=	-DFREEBSD_FILESDIR:STRING=${FILESDIR}

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
