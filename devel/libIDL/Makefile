# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/libIDL/Makefile,v 1.7 2010/04/02 17:27:42 kwm Exp $

PORTNAME=	libIDL
PORTVERSION=	0.8.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for creating trees of CORBA IDL files

USES=		bison pathfix pkgconfig gettext
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		libIDL2

NO_STAGE=	yes
.include <bsd.port.mk>
