# New ports collection makefile for:	libpafe-ruby
# Date created:				21 February 2010
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libpafe-ruby
PORTVERSION=	0.0.8
#PORTREVISION=	0
CATEGORIES=	devel ruby
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Ruby binding for libpafe

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	pafe:${PORTSDIR}/devel/libpafe

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/pasori.so

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
