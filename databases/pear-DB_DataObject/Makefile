# Created by: Antonio Carlos Venancio Junior (<antonio@php.net>)
# $FreeBSD$

PORTNAME=	DB_DataObject
PORTVERSION=	1.11.5
PORTREVISION=	1
CATEGORIES=	databases pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	SQL Builder, Object Interface to Database Tables

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/docs/LICENCE.txt

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}DB>=1.9.3:databases/pear-DB@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Date>=1.4.7:devel/pear-Date@${PHP_FLAVOR}
RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}DB>=1.9.3:databases/pear-DB@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Date>=1.4.7:devel/pear-Date@${PHP_FLAVOR}

USES=		pear

OPTIONS_DEFINE=	PEAR_MDB2 PEAR_VALIDATE

PEAR_MDB2_DESC=		PEAR::MDB2 support
PEAR_VALIDATE_DESC=	PEAR::Validate support

PEAR_MDB2_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}MDB2>=2.5.0.b5:databases/pear-MDB2@${PHP_FLAVOR}
PEAR_VALIDATE_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Validate>=0.8.5:devel/pear-Validate@${PHP_FLAVOR}

.include <bsd.port.mk>
