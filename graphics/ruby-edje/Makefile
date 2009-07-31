# New ports collection makefile for:	ruby-edje
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	edje
PORTVERSION=	20080302
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-edje-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ruby bindings for Edje library

BUILD_DEPENDS=	${RUBY_SA}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RAKE=	yes
USE_EFL=	edje

RUBY_SA=	${RUBY_SITEARCHLIBDIR}

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}; ${SETENV} EDJE_PREFIX=${LOCALBASE} ${RAKE_BIN})

do-install:
	@(cd ${WRKSRC}; ${SETENV} EDJE_PREFIX=${LOCALBASE} \
		${RAKE_BIN} install)

.include <bsd.port.post.mk>
