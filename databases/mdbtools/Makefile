# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mdbtools
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	https://github.com/brianb/mdbtools/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

LICENSE=	GPLv2

# To build man-pages
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		txt2man:${PORTSDIR}/textproc/txt2man
LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC

USES=		bison iconv libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.am
USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	-a -c -f
USE_LDCONFIG=	yes
USE_GNOME=	glib20
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-unixodbc=${LOCALBASE}
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_XORG+=	x11
USE_GNOME+=	gnomeprefix libgnomeui gconf2 intltool
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(srcdir)/$$<|$$(srcdir)/$$>|g' \
		${WRKSRC}/doc/Makefile.am

post-configure:
	@${REINPLACE_CMD} -e 's|^install-man:.*|install-man: install-man1|' \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
