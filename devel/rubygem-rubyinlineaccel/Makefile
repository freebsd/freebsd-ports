# New ports collection makefile for:	rubygem-rubyinlineaccel
# Date created:		2007-09-28
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	rubyinlineaccel
PORTVERSION=	0.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	RubyInlineAcceleration-${PORTVERSION}

MAINTAINER=	tota@rtfm.jp
COMMENT=	An extension to RubyInline

BUILD_DEPENDS=	rubygem-inline>=3.6.3:${PORTSDIR}/devel/rubygem-inline
RUN_DEPENDS=	${BUILD_DEPENDS}

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
