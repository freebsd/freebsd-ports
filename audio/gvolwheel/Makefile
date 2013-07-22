# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gvolwheel
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Volume mixer

LICENSE=	GPLv3

BUILD_DEPENDS=	intltoolize:${PORTSDIR}/textproc/intltool

CONFIGURE_ARGS+=--enable-oss
GNU_CONFIGURE=	yes
USES=		pkgconfig pathfix iconv
USE_GMAKE=	yes
USE_GNOME=	gtk30

OPTIONS_DEFINE=	NLS
NLS_DESC=	Native language support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
USES+=		gettext
.endif

pre-configure:
	${ECHO} "${DOCSDIR}"
	${REINPLACE_CMD} -e 's|linux/soundcard|sys/soundcard|g' \
		${WRKSRC}/src/callbacks.c ${WRKSRC}/src/actions.c

.include <bsd.port.mk>
