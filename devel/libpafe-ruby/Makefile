# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpafe-ruby
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Ruby binding for libpafe

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpafe.so:devel/libpafe

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/pasori.so

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}

.include <bsd.port.mk>
