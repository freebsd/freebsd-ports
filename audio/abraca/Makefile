# Created by: Olivier Smedts <olivier@gid0.org>
# $FreeBSD$

PORTNAME=	abraca
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/Abraca/Abraca/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK2 client for the XMMS2 music player

BUILD_DEPENDS=	${LOCALBASE}/bin/valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libxmmsclient.so:${PORTSDIR}/audio/xmms2 \
		libgee.so:${PORTSDIR}/devel/libgee06

USES=		pkgconfig scons
USE_GNOME=	gtk30

MAKE_ARGS=	MANDIR=${MANPREFIX}/man

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-configure:
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's/%%NLS%%/1/' ${WRKSRC}/SConstruct
.else
	@${REINPLACE_CMD} -e 's/%%NLS%%/0/' ${WRKSRC}/SConstruct
.endif

.include <bsd.port.mk>
