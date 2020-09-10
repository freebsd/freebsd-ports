# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mdbtools
DISTVERSION=	0.8.2
CATEGORIES=	databases

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

LICENSE=	GPLv2

# To build man-pages
BUILD_DEPENDS=	gawk:lang/gawk \
		txt2man:textproc/txt2man
LIB_DEPENDS=	libodbc.so:databases/unixODBC
# TODO  libmswstr: https://github.com/leecher1337/libmswstr
#LIB_DEPENDS+=	libmswstr.so:databases/libmswstr

USES=		autoreconf bison gettext-runtime gnome iconv libtool pathfix \
		pkgconfig readline
USE_LDCONFIG=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--enable-gtk-doc \
		--with-unixodbc=${LOCALBASE}

USE_GITHUB=	yes
GH_ACCOUNT=	cyberemissary

OPTIONS_DEFINE=	DOCS GNOME
OPTIONS_SUB=	yes

INSTALL_TARGET=	install-strip

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO

GNOME_CONFIGURE_ENABLE=	gmdb2
GNOME_USE=		GNOME=gconf2 \
			GNOME=gdkpixbuf2 \
			GNOME=gnomeprefix \
			GNOME=intltool \
			GNOME=libgnomeui

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
