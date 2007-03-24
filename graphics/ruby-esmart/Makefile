# New ports collection makefile for:	ruby-esmart
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	esmart
PORTVERSION=	20061008
PORTREVISION=	0
CATEGORIES=	graphics ruby
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-esmart-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ruby bindings for Esmart library

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake \
		${RUBY_SA}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas \
		${RUBY_SA}/ecore/rb_window.h:${PORTSDIR}/devel/ruby-ecore

USE_BZIP2=	yes
USE_RUBY=	yes
USE_EFL_ESMART=	trans_x11

RUBY_SA=	${RUBY_SITEARCHLIBDIR}

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}; ${SETENV} ESMART_PREFIX=${LOCALBASE} \
		${LOCALBASE}/bin/rake)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ESMART_PREFIX=${LOCALBASE} \
		${LOCALBASE}/bin/rake install)

.include <bsd.port.post.mk>
