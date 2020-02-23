# Created by: Andy Gilligan <andy@evo6.org>
# $FreeBSD$

PORTNAME=	bulksms
PORTVERSION=	0.1
CATEGORIES=	comms python
MASTER_SITES=	http://bsdtec.com/freebsd/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	craig001@lerwick.hopto.org
COMMENT=	Python client for the BulkSMS.co.uk HTTP API

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=			python:2.7
USE_PYTHON=		distutils
PYDISTUTILS_PKGNAME=	BulkSMS
PYDISTUTILS_PKGVERSION=	1.0

WRKSRC=		${WRKDIR}/bulksms

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
