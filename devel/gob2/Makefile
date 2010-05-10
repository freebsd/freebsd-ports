# New ports collection makefile for:   gob2
# Date created:        09 November 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gob2
PORTVERSION=	2.0.17
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A preprocessor for making GObjects with inline C

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/gob2 share/aclocal/gob2.m4 ${EXAMPLES:S/^/%%EXAMPLESDIR%%\//}
PLIST_DIRS=	%%EXAMPLESDIR%%

MAN1=		gob2.1

EXAMPLES=	GNOME_Foo_SomeInterface.idl \
		README \
		foo-some-interface.gob \
		gtk-button-count.gob \
		my-glade-main.c \
		my-glade.glade \
		my-glade.gob \
		my-person.gob

post-install:
	${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
