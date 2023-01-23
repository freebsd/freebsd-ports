PORTNAME=	kanatest
PORTVERSION=	0.4.10
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	Clockwork6400@protonmail.com
COMMENT=	Japanese kana (Hiragana and Katakana) simple flashcard tool
WWW=		https://github.com/Clockwork6400/kanatest

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz
USES=		gettext gmake pkgconfig desktop-file-utils
USE_GNOME+=	gtk30 libxml2 pango atk cairo gdkpixbuf2 glib20
GNU_CONFIGURE=	yes
MAKE_ENV+=	LIBINTL="-lintl"

USE_GITHUB=	yes
GH_ACCOUNT=	Clockwork6400

pre-configure:
	${CHMOD} +x ${WRKSRC}/configure
	${REINPLACE_CMD} '/LIBS/s|-lxml|-L${LOCALBASE}/lib &|' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e '/^%.mo:/,/^$$/s/test[^;]*/${TRUE}/' \
		-e '\|/usr/bin| { s||${LOCALBASE}/bin|; s|=|?=|; }' \
		${WRKSRC}/po/Makefile.in
	${REINPLACE_CMD} -e '/GTK_WIDGET_SET_FLAGS/ { \
		s//gtk_widget_set_can_default/; \
		s/GTK_CAN_DEFAULT/TRUE/; }' \
		-e '/GTK_WIDGET_UNSET_FLAGS/ { \
		s//gtk_widget_set_can_focus/; \
		s/GTK_CAN_FOCUS/FALSE/; }' \
		${WRKSRC}/src/about.c \
		${WRKSRC}/src/chart.c \
		${WRKSRC}/src/gui.c \
		${WRKSRC}/src/options.c \
		${WRKSRC}/src/stats.c

.include <bsd.port.mk>
