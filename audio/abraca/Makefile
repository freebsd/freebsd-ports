# New ports collection makefile for:	abraca
# Date created:				31 May 2005
# Whom:					Olivier Smedts <olivier@gid0.org>
#
# $FreeBSD$
#

PORTNAME=	abraca
PORTVERSION=	0.7.0
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/Abraca/Abraca/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Abraca is a GTK2 client for the XMMS2 music player

BUILD_DEPENDS=	${LOCALBASE}/bin/valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	xmmsclient.6:${PORTSDIR}/audio/xmms2 \
		gee.2:${PORTSDIR}/devel/libgee

USE_SCONS=	yes
USE_GNOME=	gtk30

SCONS_ARGS=	MANDIR=${MANPREFIX}/man

MAN1=		abraca.1
MANCOMPRESSED=	yes

OPTIONS=	NLS	"Enable gettext support" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS='@comment '
.else
PLIST_SUB+=	NLS=''
USE_GETTEXT=	yes
.endif

post-configure:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's/%%NLS%%/0/' ${WRKSRC}/SConstruct
.else
	@${REINPLACE_CMD} -e 's/%%NLS%%/1/' ${WRKSRC}/SConstruct
.endif

.include <bsd.port.mk>
