# New ports collection Makefile for:	onyx
# Date created:		15 May 2001
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	onyx
PORTVERSION=	2.3.0
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/

MAINTAINER=	jasone@FreeBSD.org

BUILD_DEPENDS=	cook:${PORTSDIR}/devel/cook

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		onyx.1
MANCOMPRESSED=	no

do-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook install)

post-install:
	@strip ${PREFIX}/bin/onyx
	@cat ${PKGMESSAGE}

.include <bsd.port.mk>
