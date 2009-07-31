# New ports collection makefile for:	ruby-esmart
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	esmart
PORTVERSION=	20080302
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-esmart-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ruby bindings for Esmart library

BUILD_DEPENDS=	${RUBY_SA}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas \
		${RUBY_SA}/ecore/rb_window.h:${PORTSDIR}/devel/ruby-ecore

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RAKE=	yes
USE_EFL_ESMART=	trans_x11 container draggies
CFLAGS+=	-I"${LOCALBASE}/include" -fPIC

RUBY_SA=	${RUBY_SITEARCHLIBDIR}

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ESMART_PREFIX=${LOCALBASE} \
		${RAKE_BIN})

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ESMART_PREFIX=${LOCALBASE} \
		${RAKE_BIN} install)

.include <bsd.port.post.mk>
