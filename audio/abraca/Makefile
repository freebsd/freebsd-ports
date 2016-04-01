# Created by: Olivier Smedts <olivier@gid0.org>
# $FreeBSD$

PORTNAME=	abraca
PORTVERSION=	0.8.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK2 client for the XMMS2 music player

BUILD_DEPENDS=	${LOCALBASE}/bin/valac:lang/vala
LIB_DEPENDS=	libxmmsclient.so:audio/xmms2 \
		libgee-0.8.so:devel/libgee
RUN_DEPENDS=	gnome-themes-standard>=3.0.0:x11-themes/gnome-themes-standard \
		gnome-icon-theme>=0:misc/gnome-icon-theme

USES=		pkgconfig waf tar:bzip2
USE_GNOME=	gtk30 intltool

MAKE_ARGS=	MANDIR=${MANPREFIX}/man
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--mandir=${PREFIX}/man

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/\.load(/s/ intltool//' \
		-e '/recurse/s/ po//' ${WRKSRC}/wscript

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
