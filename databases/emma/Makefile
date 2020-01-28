# Created by: Junji NAKANISHI <jun-g@daemonfreaks.com>
# $FreeBSD$

PORTNAME=	emma
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://www.fastflo.de/files/emma/downloads/python_src/

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Extendable MySQL managing assistant

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-03-01

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:databases/py-MySQLdb@${PY_FLAVOR}

USES=		gnome python:2.7
USE_GNOME=	pygtk2
USE_PYTHON=	distutils

pre-patch:
	@${REINPLACE_CMD} -e 's|python2.4|env python|' ${WRKSRC}/emma

.include <bsd.port.mk>
