# Created by: ijliao
# $FreeBSD$

PORTNAME=	cbrpager
PORTVERSION=	0.9.22
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for cbr (comic book archive) files

LICENSE=	GPLv3

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	libgnomeui

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		%%NLS%%share/locale/es/LC_MESSAGES/${PORTNAME}.mo \
		%%NLS%%share/locale/fr/LC_MESSAGES/${PORTNAME}.mo

DESKTOP_ENTRIES="cbrPager" "Comic book viewer" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;Viewer;GNOME;" ""

.include <bsd.port.options.mk>

post-configure:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} 's|src po|src|' ${WRKSRC}/Makefile
.endif

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
