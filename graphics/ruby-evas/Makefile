# New ports collection makefile for:	ruby-evas
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	20080302
PORTREVISION=	0
CATEGORIES=	graphics ruby
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-evas-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ruby bindings for Evas library

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake

USE_BZIP2=	yes
USE_RUBY=	yes
USE_EFL=	evas

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}; ${SETENV} EVAS_PREFIX=${LOCALBASE} \
		${LOCALBASE}/bin/rake)

do-install:
	@(cd ${WRKSRC}; ${SETENV} EVAS_PREFIX=${LOCALBASE} \
		${LOCALBASE}/bin/rake install)

.include <bsd.port.post.mk>
