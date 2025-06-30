PORTNAME=	verbiste
PORTVERSION=	0.1.49
PORTREVISION=	1
CATEGORIES=	french education textproc
MASTER_SITES=	http://sarrazip.com/dev/

MAINTAINER=	dereckson@gmail.com
COMMENT=	French verb conjugator/deconjugator
WWW=		http://sarrazip.com/dev/verbiste.html

LICENSE=	GPLv2

USES=		gnome iconv:wchar_t pathfix pkgconfig libtool localbase \
		shebangfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	${WRKSRC}/examples/*.pl

TEST_TARGET=	check

OPTIONS_DEFINE=	GTK2 DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USES+=		gettext
USE_GNOME+=	cairo gdkpixbuf gtk20
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
PLIST_SUB+=	HASGTK=""
.else
CONFIGURE_ARGS+=--without-gtk-app
PLIST_SUB+=	HASGTK="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in README *.java *.c
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
