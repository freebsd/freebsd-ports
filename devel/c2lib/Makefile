# New ports collection makefile for:	c2lib
# Date created:		2002-12-22
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2lib
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/_file/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of basic structures and memory allocators for C

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	cdoc:${PORTSDIR}/devel/cdoc \
		make+:${PORTSDIR}/devel/makeplus
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre

USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
PLIST_SUB=	VERSION=${PORTVERSION}
CONFIGURE_ENV=	MAKEPLUS_HOME=${MAKEPLUS_HOME}
MAKE_ENV=	MAKEPLUS_HOME=${MAKEPLUS_HOME}
MAKEPLUS_HOME=	${LOCALBASE}/share/makeplus

.include "${.CURDIR}/files/manpages.mk"

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make+

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make+ install

.include <bsd.port.mk>
