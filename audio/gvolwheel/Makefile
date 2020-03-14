# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gvolwheel
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Volume mixer

LICENSE=	GPLv3

CONFIGURE_ARGS+=--enable-oss
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake gnome iconv pkgconfig
USE_GNOME=	gtk30 intltool

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="GVolWheel" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "GTK;AudioVideo;Audio;Mixer;" true

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${LN} -sf gvolwheel/audio-volume-high.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
