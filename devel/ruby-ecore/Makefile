# New ports collection makefile for:	ruby-ecore
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	ecore
PORTVERSION=	20060516
CATEGORIES=	devel ruby
MASTER_SITES=	http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-ecore-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Ruby bindings for Ecore library

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake \
		${RUBY_SITEARCHLIBDIR}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas
LIB_DEPENDS=	ecore.1:${PORTSDIR}/x11/ecore

USE_BZIP2=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}; ${SETENV} ECORE_PREFIX=${X11BASE} \
		${LOCALBASE}/bin/rake)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ECORE_PREFIX=${X11BASE} \
		${LOCALBASE}/bin/rake install)

.include <bsd.port.post.mk>
