# ex:ts=8
# New ports collection makefile for:	ftpcube
# Date created:			Dec 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ftpcube
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	ftp python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical FTP Client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wx/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' ${WRKSRC}/setup.cfg
	
.include <bsd.port.mk>
