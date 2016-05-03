# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rugged
PORTVERSION=	0.24.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rugged is a Ruby binding to the libgit2 linkable library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake \
		libgit2>=${PORTVERSION:R}:devel/libgit2
LIB_DEPENDS=	libgit2.so:devel/libgit2

CONFIGURE_ARGS=	--use-system-libraries
USE_RUBY=	yes
USES=		gem pkgconfig

.include <bsd.port.mk>
