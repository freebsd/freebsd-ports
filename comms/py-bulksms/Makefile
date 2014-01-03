# Created by: Andy Gilligan <andy@evo6.org>
# $FreeBSD$

PORTNAME=	bulksms
PORTVERSION=	0.1
CATEGORIES=	comms python
MASTER_SITES=	http://ngsoftwareltd.com/freebsd/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	craig001@lerwick.hopto.org
COMMENT=	Python client for the BulkSMS.co.uk HTTP API

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	BulkSMS
PYDISTUTILS_PKGVERSION=	1.0

WRKSRC=		${WRKDIR}/bulksms

NO_STAGE=	yes

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
