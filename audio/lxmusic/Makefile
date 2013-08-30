# Created by: Eric Turgeon <ericturgeon.bsd at gmail.com>
# $FreeBSD$

PORTNAME=	lxmusic
PORTVERSION=	0.4.5
CATEGORIES=	audio
MASTER_SITES=	SF/ghostbsdproject/package/LXMusic/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	LXDE music player based on xmms2

LICENSE=	MIT GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	xmmsclient:${PORTSDIR}/audio/xmms2 \
		notify:${PORTSDIR}/devel/libnotify

USES=		gmake desktop-file-utils
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|data po|data|' \
		${WRKSRC}/Makefile.in

.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
