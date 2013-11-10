# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mdbtools
PORTVERSION=	0.7.1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/brianb/mdbtools/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

LICENSE=	GPLv2

# To build man-pages
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		txt2man:${PORTSDIR}/textproc/txt2man
LIB_DEPENDS=	libiodbc.so:${PORTSDIR}/databases/libiodbc

FETCH_ARGS?=	-Fpr
USES=		bison pkgconfig iconv
USE_AUTOTOOLS=	libtool autoconf automake
USE_LDCONFIG=	yes
USE_GNOME=	glib20
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-iodbc=${LOCALBASE}

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_XORG=	x11
USES+=		pathfix
USE_GNOME+=	gnomeprefix libgnomeui gconf2 intltool
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fpic
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|$$(srcdir)/$$<|$$(srcdir)/$$>|g' \
		${WRKSRC}/doc/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -if

post-configure:
	@${REINPLACE_CMD} -e 's|^install-man:.*|install-man: install-man1|' \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
