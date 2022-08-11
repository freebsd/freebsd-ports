PORTNAME=	libarea
PORTVERSION=	20191031
CATEGORIES=	devel cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CAM-related software for profile and pocketing operations

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	${PY_BOOST}

USES=		cmake python

USE_GITHUB=	yes
GH_ACCOUNT=	Heeks
GH_TAGNAME=	2752cd9

USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's,COMMAND python ,COMMAND ${PYTHON_CMD} , ; \
		s,COMMAND python-config ,COMMAND ${PYTHON_CMD}-config ,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
