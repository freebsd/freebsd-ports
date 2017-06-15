# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gob2
PORTVERSION=	2.0.17
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Preprocessor for making GObjects with inline C

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USES=		pkgconfig gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/gob2 share/aclocal/gob2.m4 ${EXAMPLES:S/^/%%EXAMPLESDIR%%\//} \
		man/man1/gob2.1.gz

EXAMPLES=	GNOME_Foo_SomeInterface.idl \
		README \
		foo-some-interface.gob \
		gtk-button-count.gob \
		my-glade-main.c \
		my-glade.glade \
		my-glade.gob \
		my-person.gob

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
