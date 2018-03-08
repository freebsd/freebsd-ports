# Created by: Antonio Carlos Venancio Junior (<antonio@php.net>)
# $FreeBSD$

PORTNAME=	Validate
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PEAR Validation class

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DATE IDNA

DATE_DESC=	Date and Time Zone Classes
DATE_RUN_DEPENDS=	${PEARDIR}/Date.php:devel/pear-Date@${PHP_FLAVOR}

IDNA_DESC=	Net_IDNA - Punycode encoding and decoding package
IDNA_RUN_DEPENDS=	${PEARDIR}/Net/IDNA.php:net/pear-Net_IDNA@${PHP_FLAVOR}

USES=		pear
NO_ARCH=	yes

.include <bsd.port.mk>
