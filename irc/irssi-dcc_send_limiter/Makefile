# New ports collection makefile for:    dcc_send_limiter
# Date created:                         23 October 2005
# Whom:                                 Timothy Redaelli <drizzt@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	dcc_send_limiter
PORTVERSION=	0.8.10
CATEGORIES=	irc
MASTER_SITES=	http://svn.irssi.org/repos/modules/trunk/ \
		http://irssi.4ever.de/files/plugins/
PKGNAMEPREFIX=	irssi-
DISTNAME=	dcc-send-limiter
EXTRACT_SUFX=	.c

PATCH_SITES=	http://www.krukowiecki.net/code/irssi/
PATCHFILES=	${DISTFILES}.diff

MAINTAINER=	drizzt@gufi.org
COMMENT=	Irssi plugin to limit the transmit speed of DCC sends

BUILD_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

USE_GNOME=	glib20
NO_WRKSUBDIR=	yes

PLIST_FILES=	lib/irssi/modules/lib${PORTNAME}.so

CFLAGS+=	-shared -fPIC -I${LOCALBASE}/include/irssi -I${LOCALBASE}/include/irssi/src -I${LOCALBASE}/include/irssi/src/core -I${LOCALBASE}/include/irssi/src/irc/core -I${LOCALBASE}/include/irssi/src/irc/dcc `pkg-config --cflags glib-2.0`

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/${DISTNAME}.so ${WRKDIR}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.so ${LOCALBASE}/${PLIST_FILES}

.include <bsd.port.mk>
