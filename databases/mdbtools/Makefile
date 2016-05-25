# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mdbtools
PORTVERSION=	0.7.1
PORTREVISION=	5
CATEGORIES=	databases

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

LICENSE=	GPLv2

# To build man-pages
BUILD_DEPENDS=	gawk:lang/gawk \
		txt2man:textproc/txt2man
LIB_DEPENDS=	libodbc.so:databases/unixODBC

OPTIONS_DEFINE=	GNOME DOCS
OPTIONS_SUB=	yes

USES=		autoreconf bison iconv libtool pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brianb
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-unixodbc=${LOCALBASE}
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO

GNOME_CONFIGURE_ENABLE=	gmdb2
GNOME_USE=	GNOME=gnomeprefix GNOME=libgnomeui GNOME=gconf2 GNOME=intltool

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
