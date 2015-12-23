# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mnemosyne
PORTVERSION=	2.3.5
PORTEPOCH=	1
CATEGORIES=	games python
MASTER_SITES=	SF/mnemosyne-proj/${PORTNAME}/${PORTNAME}-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mnemosyne-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4>=4.5:${PORTSDIR}/devel/py-qt4 \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.2.0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=3.2:${PORTSDIR}/www/py-cherrypy \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.2:${PORTSDIR}/www/py-webob

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
