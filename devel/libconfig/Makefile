PORTNAME=	libconfig
DISTVERSION=	1.8.2
CATEGORIES=	devel
MASTER_SITES=	https://hyperrealm.github.io/${PORTNAME}/dist/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	Simple library for processing structured configuration files
WWW=		https://hyperrealm.github.io/libconfig/

LICENSE=	LGPL21

USES=		libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFLICTS=	wand-libconfig

TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-examples

OPTIONS_DEFINE=	INFO
OPTIONS_DEFAULT=INFO

INFO_INFO=	libconfig
INFO_CONFIGURE_OFF=	--disable-doc
INFO_USES=	makeinfo

.include <bsd.port.mk>
