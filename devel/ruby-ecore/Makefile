# New ports collection makefile for:	ruby-ecore
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	ecore
PORTVERSION=	20080302
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ruby bindings for Ecore library

BUILD_DEPENDS=	${RUBY_SA}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RAKE=	yes
USE_EFL=	ecore
USE_EFL_ECORE=	x11 con job evas

RUBY_SA=	${RUBY_SITEARCHLIBDIR}

.include <bsd.port.pre.mk>

do-build:
	@(cd ${WRKSRC}; ${SETENV} ECORE_PREFIX=${LOCALBASE} \
		${RAKE_BIN})

do-install:
	@(cd ${WRKSRC}; ${SETENV} ECORE_PREFIX=${LOCALBASE} \
		${RAKE_BIN} install)

.include <bsd.port.post.mk>
