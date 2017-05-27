# Created by: Jov <amutu@amutu.com`>
# $FreeBSD$

PORTNAME=	dnsforwarder
PORTVERSION=	20170319
CATEGORIES=	dns

MAINTAINER=	amutu@amutu.com
COMMENT=	Dnsforwarder is A simple DNS forwarder

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	holmium
GH_TAGNAME=	441ef2081651020ac1bd42f91017dbdad044c7d8

USES=		localbase

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ccflags=no

PLIST_FILES=	bin/dnsforwarder

MAKEFILE=	makefile

.include <bsd.port.mk>
