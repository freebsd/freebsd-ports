# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	adns
DISTVERSION=	1.4
DISTVERSIONSUFFIX=	-py1
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Python module to resolve IPs to host names

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

LIB_DEPENDS=	libadns.so:dns/adns

USES=		localbase python:3.4+
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|1.4-py1|1.4|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
