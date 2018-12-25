# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	libarea
PORTVERSION=	20160313
PORTREVISION=	9
CATEGORIES=	devel cad

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	CAM-related software for profile and pocketing operations

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	${PY_BOOST}

USE_GITHUB=	yes
GH_ACCOUNT=	Heeks
GH_TAGNAME=	f1986ac

USES=		cmake python
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's,COMMAND python ,COMMAND ${PYTHON_CMD} , ; \
		s,COMMAND python-config ,COMMAND ${PYTHON_CMD}-config ,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
