# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	ocempgui
PORTVERSION=	0.2.9
PORTREVISION=	9
CATEGORIES=	devel python
MASTER_SITES=	SF/ocemp/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OcempGUI-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI toolkit in python

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:devel/py-game
RUN_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:devel/py-game

USES=		python:2
USE_GNOME=	atk
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@DATAPATH@|${DATADIR}|' ${WRKSRC}/ocempgui/widgets/Constants.py

.include <bsd.port.mk>
