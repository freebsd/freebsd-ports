# Created by: Jeremy Lea <reg@shale.csir.co.za>
# $FreeBSD$

PORTNAME=	gnome-chess
PORTVERSION=	3.10.2
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GUI chess front-end to crafy, for the GNOME Desktop Environment

RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty
BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty \
		itstool:${PORTSDIR}/textproc/itstool \
		xmllint:${PORTSDIR}/textproc/libxml2 \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		gmake pkgconfig desktop-file-utils shared-mime-info tar:xz
USE_GL=		gl glu
USE_GNOME=	gtk30 intlhack librsvg2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_ARGS=	XML_I18N_UPDATE="${TRUE}" XML_I18N_EXTRACT="${TRUE}"
DATADIR=	${PREFIX}/share/gnome-chess

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
