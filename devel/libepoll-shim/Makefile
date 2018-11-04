# Created by: Johannes Lundberg <johalun0@gmail.com>
# $FreeBSD$

PORTNAME=	libepoll-shim
PORTVERSION=	0.0.20161220
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	dbd89815cc3a.patch:-p1 dc10c10f11d6.patch:-p1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	epoll shim implemented using kevent

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_PROJECT=	epoll-shim
GH_TAGNAME=	c04b26b

USE_LDCONFIG=	yes

USES=		compiler uidfix
MAKE_ARGS=	INCSDIR=${PREFIX}/include/libepoll-shim/sys \
		LIBDIR=${PREFIX}/lib WITHOUT_PROFILE=yes

.include <bsd.port.pre.mk>

post-patch:
.if "${CHOSEN_COMPILER_TYPE}" == "gcc"
	@${REINPLACE_CMD} -e 's|Wno-missing-variable-declarations|Wno-missing-declarations|' \
		-e 's|-Wno-thread-safety-analysis||' ${WRKSRC}/Makefile
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/libepoll-shim/sys

.include <bsd.port.post.mk>
