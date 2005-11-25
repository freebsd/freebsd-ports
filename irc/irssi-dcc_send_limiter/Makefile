# New ports collection makefile for:    dcc_send_limiter
# Date created:                         23 October 2005
# Whom:                                 Timothy Redaelli <drizzt@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	dcc_send_limiter
PORTVERSION=	0.8.9
CATEGORIES=	irc
.for _PREFIX in www fi hu de uk ie lt be dk ca lv
MASTER_SITES+=	http://${_PREFIX}.irssi.org/files/plugins/
.endfor
DISTNAME=	dcc-send-limiter
EXTRACT_SUFX=	.c

PATCH_SITES=	http://www.krukowiecki.net/code/irssi/
PATCHFILES=	${DISTFILES}.diff

MAINTAINER=	drizzt@gufi.org
COMMENT=	Irssi plugin to limit the transmit speed of DCC sends

USE_GNOME=	pkgconfig
NO_WRKSUBDIR=	yes

PLIST_FILES=	lib/irssi/modules/lib${PORTNAME}.so

CFLAGS+=	-shared -I${LOCAL_IRSSIDIR} -I${LOCAL_IRSSIDIR}/src -I${LOCAL_IRSSIDIR}/src/core -I${LOCAL_IRSSIDIR}/src/irc/core -I${LOCAL_IRSSIDIR}/src/irc/dcc `pkg-config --cflags ${LOCAL_GLIB}`

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/include/irssi/irssi-version.h)
PKGNAMEPREFIX=	irssi-
BUILD_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
EXTRACT_DEPENDS=${WRKDIR}/../../../${LOCAL_SRCDIR}/work/irssi-${LOCAL_IRSSIVER}/Makefile:${PORTSDIR}/${LOCAL_SRCDIR}:configure
LOCAL_SRCDIR=	irc/irssi
LOCAL_IRSSIDIR=	${WRKDIR}/../../../${LOCAL_SRCDIR}/work/irssi-${LOCAL_IRSSIVER}
LOCAL_IRSSIVER=	0.8.9
.if exists(${LOCALBASE}/include/glib-2.0/glib.h)
LOCAL_GLIB=	glib-2.0
.else
LOCAL_GLIB=	glib
.endif
.else
PKGNAMEPREFIX=	irssi-devel-
BUILD_DEPENDS=  ${LOCALBASE}/include/irssi/irssi-version.h:${PORTSDIR}/irc/irssi-devel
LOCAL_IRSSIDIR=	${LOCALBASE}/include/irssi
LOCAL_GLIB=glib-2.0
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/${DISTNAME}.so ${WRKDIR}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.so ${LOCALBASE}/${PLIST_FILES}

.include <bsd.port.post.mk>
