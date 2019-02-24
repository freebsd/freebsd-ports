# Created by: dindin
# $FreeBSD$

PORTNAME=	flamerobin
PORTVERSION=	0.9.2
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI administration tool for firebird database

DEPRECATED=	Abandonware since 2009, does not work with newer version of wxGTK
EXPIRATION_DATE=	2019-03-24

LICENSE=	expat
LICENSE_NAME=	FlameRobin Expat
LICENSE_FILE=	${WRKSRC}/docs/fr_license.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler firebird
GNU_CONFIGURE=	yes
USE_WX=		2.8
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_PREMK=	yes

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
.if ${COMPILER_TYPE} == gcc
CONFIGURE_ARGS=	--disable-precomp-headers
.endif

.include <bsd.port.post.mk>
