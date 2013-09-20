# Created by: Junji NAKANISHI <jun-g@daemonfreaks.com>
# $FreeBSD$

PORTNAME=	emma
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://www.fastflo.de/files/emma/downloads/python_src/

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Extendable MySQL managing assistant

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:${PORTSDIR}/databases/py-MySQLdb

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e 's|python2.4|env python|' ${WRKSRC}/emma

.include <bsd.port.mk>
