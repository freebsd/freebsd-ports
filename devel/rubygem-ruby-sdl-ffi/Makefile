# New ports collection makefile for:   rubygem-ruby-sdl-ffi
# Date created:    28 April 2010
# Whom:		Christoph Kick
#
# $FreeBSD$
#

PORTNAME=		ruby-sdl-ffi
PORTVERSION=		0.2
CATEGORIES=		devel rubygems
MASTER_SITES=		RG

MAINTAINER=	kick.christoph@googlemail.com
COMMENT=	Low-level binding to SDL and related libraries using Ruby-FFI

BUILD_DEPENDS=	rubygem-nice-ffi>=0.3:${PORTSDIR}/devel/rubygem-nice-ffi
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
