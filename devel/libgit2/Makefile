# New ports collection makefile for:	libgit2
# Date created:		2011-05-27
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgit2
PORTVERSION=	0.15.0
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/libgit2/libgit2/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Portable, pure C implementation of the Git core

LICENSE=	GPLv2

USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: thread-local storage not supported
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/pkgconfig|/../libdata/pkgconfig|" ${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
