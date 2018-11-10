# Created by: Nikos Ntarmos <ntarmos@ceid.upatras.gr>
# $FreeBSD$

PORTNAME=	libconfig
PORTVERSION=	1.7.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	Simple library for manipulating structured configuration files

LICENSE=	LGPL21

BUILD_DEPENDS=	makeinfo:print/texinfo

USES=	autoreconf libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

USE_GITHUB=	YES
GH_ACCOUNT=	hyperrealm

CONFLICTS=	wand-libconfig-[0-9]*

INFO=	libconfig

.include <bsd.port.mk>
