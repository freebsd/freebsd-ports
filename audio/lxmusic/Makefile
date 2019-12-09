# Created by: Eric Turgeon <ericturgeon.bsd at gmail.com>
# $FreeBSD$

PORTNAME=	lxmusic
PORTVERSION=	0.4.7
CATEGORIES=	audio
MASTER_SITES=	SF/lxde/LXMusic%20%28music%20player%29/LXMusic%20${PORTVERSION:R}.x/

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	LXDE music player based on xmms2

LICENSE=	MIT GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxmmsclient.so:audio/xmms2 \
		libnotify.so:devel/libnotify

USES=		desktop-file-utils gettext-tools gmake gnome localbase \
		pkgconfig tar:xz
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

LDFLAGS+=	-lpthread

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
