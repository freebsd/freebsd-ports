# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rugged
PORTVERSION=	0.21.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rugged is a Ruby binding to the libgit2 linkable library

LICENSE=	MIT

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake \
		libgit2>=${PORTVERSION}:${PORTSDIR}/devel/libgit2
LIB_DEPENDS=	libgit2.so:${PORTSDIR}/devel/libgit2

USE_RUBY=	yes
USES=		pkgconfig
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes

CONFIGURE_ARGS=	--use-system-libraries

.include <bsd.port.mk>
