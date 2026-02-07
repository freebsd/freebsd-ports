PORTNAME=	pructl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jmg@FreeBSD.org
# The maintainer says, if you're actively using this you are free to
# take this port.
COMMENT=	Utilities to interface with PRUs
WWW=		https://bitbucket.org/rpaulo/pructl

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpru.so:devel/libpru

USES=		cmake libedit
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	rpaulo

LDFLAGS+=	-lBlocksRuntime

.include <bsd.port.mk>
