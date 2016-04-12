# Created by: Eric Turgeon <ericturgeon.bsd at gmail.com>
# $FreeBSD$

PORTNAME=	lxmusic
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/ghostbsdproject/package/LXMusic/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	LXDE music player based on xmms2

LICENSE=	MIT GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	libxmmsclient.so:audio/xmms2 \
		libnotify.so:devel/libnotify

USES=		gmake desktop-file-utils pkgconfig
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
