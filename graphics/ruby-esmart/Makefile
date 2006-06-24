# New ports collection makefile for:	ruby-esmart
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	esmart
PORTVERSION=	20060516
CATEGORIES=	graphics ruby
MASTER_SITES=	http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-esmart-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Ruby bindings for Esmart library

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake \
		${RUBY_SITEARCHLIBDIR}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas \
		${RUBY_SITEARCHLIBDIR}/ecore/rb_window.h:${PORTSDIR}/devel/ruby-ecore
LIB_DEPENDS=	esmart_trans_x11.0:${PORTSDIR}/graphics/esmart

USE_BZIP2=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}; ${SETENV} ESMART_PREFIX=${X11BASE} \
		${LOCALBASE}/bin/rake)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ESMART_PREFIX=${X11BASE} \
		${LOCALBASE}/bin/rake install)

.include <bsd.port.post.mk>
