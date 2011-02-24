# New ports collection makefile for:	abraca
# Date created:				31 May 2005
# Whom:					Olivier Smedts <olivier@gid0.org>
#
# $FreeBSD$
#

PORTNAME=	abraca
PORTVERSION=	0.5.0
CATEGORIES=	audio
MASTER_SITES=	http://abraca.xmms.se/attachments/download/128/

MAINTAINER=	olivier@gid0.org
COMMENT=	Abraca is a GTK2 client for the XMMS2 music player

BUILD_DEPENDS=	${LOCALBASE}/bin/valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	xmmsclient.6:${PORTSDIR}/audio/xmms2 \
		gee.2:${PORTSDIR}/devel/libgee

USE_BZIP2=	yes
USE_SCONS=	yes
USE_GNOME=	gtk20

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/src/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
