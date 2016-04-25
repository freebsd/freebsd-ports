# Created by: dindin
# $FreeBSD$

PORTNAME=	flamerobin
PORTVERSION=	0.9.2
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI administration tool for firebird database

LICENSE=	expat
LICENSE_NAME=	FlameRobin Expat
LICENSE_FILE=	${WRKSRC}/docs/fr_license.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler firebird
USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_PREMK=	yes
WX_UNICODE=	yes

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
.if ${COMPILER_TYPE} == gcc
CONFIGURE_ARGS=	--disable-precomp-headers
.endif

.include <bsd.port.post.mk>
