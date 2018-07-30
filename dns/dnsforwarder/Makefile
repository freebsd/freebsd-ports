# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	dnsforwarder
PORTVERSION=	6.1.15
CATEGORIES=	dns
PORTEPOCH=	1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dnsforwarder is A simple DNS forwarder

LICENSE=	GPLv3
LICENSE_FILES= ${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		localbase

USE_GITHUB=	yes
GH_ACCOUNT=	holmium

PLIST_FILES=	bin/dnsforwarder
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

.include <bsd.port.mk>
