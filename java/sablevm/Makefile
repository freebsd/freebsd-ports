# New ports collection makefile for:    sablevm
# Date created:         		9 July 2002
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sablevm
PORTVERSION=	0.1.6
CATEGORIES=	java
MASTER_SITES=	http://unc.dl.sourceforge.net/sablevm/

MAINTAINER=	archie@freebsd.org

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		ffi.2:${PORTSDIR}/devel/libffi
RUN_DEPENDS=	${LOCALBASE}/lib/sablepath/libjavalang.a:${PORTSDIR}/java/sablepath

PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
