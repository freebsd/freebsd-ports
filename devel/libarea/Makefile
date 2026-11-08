PORTNAME=	libarea
PORTVERSION=	20191031
PORTREVISION=	2
CATEGORIES=	devel cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CAM-related software for profile and pocketing operations
WWW=		https://github.com/heeks/libarea

LICENSE=	BSD3CLAUSE

DEPRECATED=	Abandoned upstream, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

LIB_DEPENDS=	${PY_BOOST}
BUILD_DEPENDS=	${PY_SETUPTOOLS}

USES=		cmake python

USE_GITHUB=	yes
GH_ACCOUNT=	Heeks
GH_TAGNAME=	2752cd9

USE_LDCONFIG=	yes

CXXFLAGS+=	"-DBOOST_TIMER_ENABLE_DEPRECATED=yes"

post-patch:
	@${REINPLACE_CMD} 's,COMMAND python ,COMMAND ${PYTHON_CMD} , ; \
		s,COMMAND python-config ,COMMAND ${PYTHON_CMD}-config ,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
