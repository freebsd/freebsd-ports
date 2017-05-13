# Created by: Johannes Lundberg <johalun0@gmail.com>
# $FreeBSD$

PORTNAME=	libepoll-shim
PORTVERSION=	0.0.20161220
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	epoll shim implemented using kevent

LICENSE=	MIT

BROKEN_powerpc64=	fails to compile: cc1: error: unrecognized command line option -Wno-missing-variable-declarations

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	epoll-shim
GH_TAGNAME=	c04b26b

USE_LDCONFIG=	yes

USES=		uidfix
MAKE_ARGS=	LIBDIR=${PREFIX}/lib INCLUDEDIR=${PREFIX}/include

post-patch:
	# -Weverything is not recognized by GCC
	@${REINPLACE_CMD} -e 's|Weverything|Wall|' ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/libepoll-shim/sys

.include <bsd.port.mk>
