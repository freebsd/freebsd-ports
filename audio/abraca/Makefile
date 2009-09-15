# New ports collection makefile for:	abraca
# Date created:				31 May 2005
# Whom:					Olivier Smedts <olivier@gid0.org>
#
# $FreeBSD$
#

PORTNAME=	abraca
PORTVERSION=	0.4
DISTVERSIONSUFFIX=-pre2
CATEGORIES=	audio
MASTER_SITES=	http://abraca.xmms.se/attachments/download/100/

MAINTAINER=	olivier@gid0.org
COMMENT=	Abraca is a GTK2 client for the XMMS2 music player

LIB_DEPENDS=	xmmsclient.5:${PORTSDIR}/audio/xmms2

USE_GMAKE=	yes
ALL_TARGET=	# defined
USE_GNOME=	gtk20

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
