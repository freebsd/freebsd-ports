# New ports collection makefile for:	kanatest
# Date created:		2004-03-27
# Whom:			S H A N <shanali@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	kanatest
PORTVERSION=	0.4.8
CATEGORIES=	games
MASTER_SITES=	http://clayo.org/kanatest/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese kana (Hiragana and Katakana) simple flashcard tool

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
MAKE_ENV+=	LIBINTL="-lintl"

post-patch:	.SILENT
	${REINPLACE_CMD} '/LIBS/s|-lxml|-L${LOCALBASE}/lib &|' \
		${WRKSRC}/configure
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
post-install:
	-update-desktop-database ${PREFIX}/share/applications

.include <bsd.port.mk>
