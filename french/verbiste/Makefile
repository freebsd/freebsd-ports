# Created by: Dan Phillips <dan-ports@dp.id.au>
# $FreeBSD$

PORTNAME=	verbiste
PORTVERSION=	0.1.44
CATEGORIES=	french textproc
MASTER_SITES=	http://sarrazip.com/dev/

MAINTAINER=	dereckson@gmail.com
COMMENT=	French verb conjugator/deconjugator

LICENSE=	GPLv2

OPTIONS_DEFINE=	GTK2 GNOME DOCS EXAMPLES

USES=		pathfix pkgconfig iconv:wchar_t libtool shebangfix
SHEBANG_FILES=	${WRKSRC}/examples/*.pl
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
PLIST_SUB+=	HASGTK=""
.else
CONFIGURE_ARGS+=--without-gtk-app
PLIST_SUB+=	HASGTK="@comment "
.endif

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	gnomeprefix libgnomeui
PLIST_SUB+=	HASGNOME=""
.else
CONFIGURE_ARGS+=--without-gnome-app --without-gnome-applet
PLIST_SUB+=	HASGNOME="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGNOME}
USES+=		gettext
PLIST_SUB+=	HASGUI=""
.else
PLIST_SUB+=	HASGUI="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in README *.java *.c
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
