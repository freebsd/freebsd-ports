# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

# Also update devel/libgit2, devel/libgit2-glib, devel/py-pygit2

PORTNAME=	rugged
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby bindings to the libgit2 library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libgit2>=${PORTVERSION:R}:devel/libgit2
LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libgmp.so:math/gmp

CONFIGURE_ARGS=	--use-system-libraries
USES=		gem pkgconfig
USE_RUBY=	yes

.include <bsd.port.mk>
