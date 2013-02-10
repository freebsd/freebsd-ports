# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	gvolwheel
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Volume mixer

LICENSE=	GPLv3

BUILD_DEPENDS=	intltoolize:${PORTSDIR}/textproc/intltool

CONFIGURE_ARGS+=--enable-oss
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk30
USE_ICONV=	yes
USE_PKGCONFIG=	yes

OPTIONS_DEFINE=	NLS
NLS_DESC=	Native language support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif

pre-configure:
	${ECHO} "${DOCSDIR}"
	${REINPLACE_CMD} -e 's|linux/soundcard|sys/soundcard|g' \
		${WRKSRC}/src/callbacks.c ${WRKSRC}/src/actions.c

.include <bsd.port.mk>
