# New ports collection makefile for:	rudiments
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudiments
PORTVERSION=	0.21
CATEGORIES=	devel
MASTER_SITES=	http://www.firstworks.com/downloads/rudiments/

MAINTAINER=	knu@FreeBSD.org

USE_GMAKE=	yes
USE_AUTOCONF_VER=213
CONFIGURE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${MAKE} doc-install
.endif

.include <bsd.port.mk>
