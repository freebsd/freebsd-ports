# New ports collection makefile for:	libpafe-ruby
# Date created:				21 February 2010
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libpafe-ruby
PORTVERSION=	0.0.7
#PORTREVISION=	0
CATEGORIES=	devel ruby
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Ruby binding for libpafe

LIB_DEPENDS=	pafe.0:${PORTSDIR}/devel/libpafe

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/pasori.so

.include <bsd.port.mk>
