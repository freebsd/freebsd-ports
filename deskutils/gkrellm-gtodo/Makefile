# New ports collection makefile for:	gkrellm-gtodo
# Date created:		Wed Apr 28 08:31:22 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	gtodo
PORTVERSION=	0.2.5.a
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://voidtrance.home.comcast.net/software/files/gtodo/ \
		http://depot.fsck.ch/mirror/distfiles/
PKGNAMEPREFIX=	gkrellm-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-0.2.5a

MAINTAINER=	ports@fsck.ch
COMMENT=	GKrellM2 plugin that tracks tasks and to-do items

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellm-gtodo.so
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PKGNAMEPREFIX}${PORTNAME}.so \
		${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
