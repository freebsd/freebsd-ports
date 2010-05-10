# New ports collection makefile for:   libIDL
# Date Created:			12 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libIDL/Makefile,v 1.7 2010/04/02 17:27:42 kwm Exp $
#

PORTNAME=	libIDL
PORTVERSION=	0.8.14
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for creating trees of CORBA IDL files

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_GNOME=	gnomehack glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		libIDL2

.include <bsd.port.mk>
