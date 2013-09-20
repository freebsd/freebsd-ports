# Created by: Timothy Redaelli <drizzt@gufi.org>
# $FreeBSD$

PORTNAME=	dcc_send_limiter
PORTVERSION=	0.8.10
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://svn.irssi.org/repos/modules/trunk/ \
		http://utenti.gufi.org/~drizzt/codes/irssi-dcc_send_limiter/
PKGNAMEPREFIX=	irssi-
DISTNAME=	dcc-send-limiter
EXTRACT_SUFX=	.c

PATCH_SITES=	http://utenti.gufi.org/~drizzt/codes/irssi-dcc_send_limiter/
PATCHFILES=	${DISTFILES}.diff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Irssi plugin to limit the transmit speed of DCC sends

BUILD_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

USES=		pkgconfig
USE_GNOME=	glib20
NO_WRKSUBDIR=	yes

PLIST_FILES=	lib/irssi/modules/lib/${DISTNAME}.so
PLIST_DIRS=	lib/irssi/modules/lib

CFLAGS+=	-shared -fPIC -I${LOCALBASE}/include/irssi -I${LOCALBASE}/include/irssi/src -I${LOCALBASE}/include/irssi/src/core -I${LOCALBASE}/include/irssi/src/irc/core -I${LOCALBASE}/include/irssi/src/irc/dcc `pkg-config --cflags glib-2.0`

NO_STAGE=	yes
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/${DISTNAME}.so ${WRKDIR}/${DISTFILES}

do-install:
	${MKDIR} ${PREFIX}/lib/irssi/modules/lib
	${CP} ${WRKSRC}/${DISTNAME}.so ${PREFIX}/lib/irssi/modules/lib/${DISTNAME}.so

.include <bsd.port.mk>
