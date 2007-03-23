# New ports collection makefile for:	py-ocempgui
# Date created:		2006-07-19
# Whom:			Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	ocempgui
PORTVERSION=	0.2.7
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ocemp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OcempGUI-${PORTVERSION}

MAINTAINER=	mva@sysfault.org
COMMENT=	GUI toolkit in python

BUILD_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:${PORTSDIR}/devel/py-game

USE_GNOME=	atk
USE_GCC=	3.4+
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -i "" -e 's|datafiles + docfiles|datafiles|g' ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
