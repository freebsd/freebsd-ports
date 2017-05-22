# Created by: Antonio Carlos Venancio Junior (<antonio@php.net>)
# $FreeBSD$

PORTNAME=	DB_DataObject
PORTVERSION=	1.11.5
CATEGORIES=	databases pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	SQL Builder, Object Interface to Database Tables

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/docs/LICENCE.txt

BUILD_DEPENDS=	pear-DB>=1.7.0:databases/pear-DB \
		pear-Date>=1.4.3:devel/pear-Date
RUN_DEPENDS=	pear-DB>=1.7.0:databases/pear-DB \
		pear-Date>=1.4.3:devel/pear-Date

USES=		pear

OPTIONS_DEFINE=	PEAR_MDB2 PEAR_VALIDATE

PEAR_MDB2_DESC=		PEAR::MDB2 support
PEAR_VALIDATE_DESC=	PEAR::Validate support

PEAR_MDB2_RUN_DEPENDS=	pear-MDB2>=2.3.0:databases/pear-MDB2
PEAR_VALIDATE_RUN_DEPENDS=	pear-Validate>=0.1.1:devel/pear-Validate

.include <bsd.port.mk>
