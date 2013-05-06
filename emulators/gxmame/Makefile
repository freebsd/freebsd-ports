# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	gxmame
DISTVERSION=	0.35beta2
PORTREVISION=	12
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.35beta2
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GXmame is a GTK frontend for xmame

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame

USES=		pathfix
USE_GNOME=	gtk20 intlhack gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-xmame-dir=${LOCALBASE}/share/xmame

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN6=		gxmame.6

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS="-Wall.*||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|__GNUC___|__GNUC__|' ${WRKSRC}/src/common.h
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' ${WRKSRC}/src/gxmame.c

.include <bsd.port.mk>
