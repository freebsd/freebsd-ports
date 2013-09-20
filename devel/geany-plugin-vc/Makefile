# $FreeBSD$

PORTNAME=	geany-plugin-vc
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

OPTIONS_DEFINE=	GTKSPELL
OPTIONS_DEFAULT=	GTKSPELL
GTKSPELL_DESC=	Spell checking support via GtkSpell

NO_STAGE=	yes
.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
# bsd.port.options.mk is already included

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	gtkspell:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=	--enable-gtkspell
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.include <bsd.port.mk>
