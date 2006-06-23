# New ports collection makefile for:	ruby-evas
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	20060516
CATEGORIES=	graphics ruby
MASTER_SITES=	http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-evas-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Ruby bindings for Evas library

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake
LIB_DEPENDS=	evas.1:${PORTSDIR}/graphics/evas

USE_BZIP2=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}; ${SETENV} EVAS_PREFIX=${X11BASE} \
		${LOCALBASE}/bin/rake)

do-install:
	@(cd ${WRKSRC}; ${SETENV} EVAS_PREFIX=${X11BASE} \
		${LOCALBASE}/bin/rake install)

.include <bsd.port.post.mk>
