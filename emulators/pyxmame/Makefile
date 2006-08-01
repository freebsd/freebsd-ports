# New ports collection makefile for:	pyxmame
# Date created:		2006-08-01
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyxmame
PORTVERSION=	0.3.1
CATEGORIES=	emulators python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple frontend for the xmame

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/pexpect.py:${PORTSDIR}/misc/py-pexpect \
		xmame:${PORTSDIR}/emulators/xmame

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
