# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gvolwheel
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Volume mixer

LICENSE=	GPLv3

BUILD_DEPENDS=	intltoolize:${PORTSDIR}/textproc/intltool

CONFIGURE_ARGS+=--enable-oss
GNU_CONFIGURE=	yes
USES=		gmake iconv pathfix pkgconfig
USE_GNOME=	gtk30

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="GVolWheel" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "GTK;AudioVideo;Audio;Mixer;" true

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|linux/soundcard|sys/soundcard|g' \
		${WRKSRC}/src/callbacks.c ${WRKSRC}/src/actions.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${LN} -sf ${PREFIX}/share/pixmaps/gvolwheel/audio-volume-high.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
