# New ports collection makefile for:	c2lib
# Date created:		2002-12-22
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2lib
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/freeware/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Library of basic structures and memory allocators for C

BUILD_DEPENDS=	cdoc:${PORTSDIR}/devel/cdoc \
		make+:${PORTSDIR}/devel/makeplus
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre

INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
PLIST_SUB=	VERSION=${PORTVERSION}

.include "${.CURDIR}/files/manpages.mk"

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make+

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make+ install

.include <bsd.port.mk>
