# $FreeBSD$

PORTNAME=	geany-plugin-vc
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

gtk2_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell
gtk3_LIB_DEPENDS=	libgtkspell3-3.so:textproc/gtkspell3

OPTIONS_DEFINE=		GTKSPELL
OPTIONS_DEFAULT=	GTKSPELL

GTKSPELL_DESC=	Spell checking support via GtkSpell
GTKSPELL_CONFIGURE_ENABLE=	gtkspell

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
