# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
#   $MCom: ports/devel/libIDL/Makefile,v 1.7 2010/04/02 17:27:42 kwm Exp $

PORTNAME=	libIDL
PORTVERSION=	0.8.14
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for creating trees of CORBA IDL files

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison:alias gettext gnome libtool localbase \
		pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc

INFO=		libIDL2

.include <bsd.port.mk>
