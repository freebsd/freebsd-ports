# New ports collection makefile for:	tkpng
# Date created:		08 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkpng
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mm@FreeBSD.org
COMMENT=	PNG support for Tcl/Tk

USE_TK=		84+
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}/generic \
		--with-tkinclude=${TK_INCLUDEDIR}/generic \
		--exec-prefix=${PREFIX} --enable-shared
CPPFLAGS=	-I${TK_INCLUDEDIR}/generic -I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	VER=${PORTVERSION} TKPKG=${TKPKG} TKLIBVER=${TKLIBVER}

.include <bsd.port.post.mk>
