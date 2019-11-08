# Created by: Timothy Redaelli <drizzt@gufi.org>
# $FreeBSD$

PORTNAME=	dcc_send_limiter
PORTVERSION=	0.8.10
PORTREVISION=	2
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

LICENSE=	GPLv2+

BUILD_DEPENDS=	irssi:irc/irssi
RUN_DEPENDS=	irssi:irc/irssi

USES=		gnome pkgconfig
USE_GNOME=	glib20
NO_WRKSUBDIR=	yes

PLIST_FILES=	lib/irssi/modules/lib/${DISTNAME}.so

CFLAGS+=	-shared -fPIC -I${LOCALBASE}/include/irssi -I${LOCALBASE}/include/irssi/src -I${LOCALBASE}/include/irssi/src/core -I${LOCALBASE}/include/irssi/src/irc/core -I${LOCALBASE}/include/irssi/src/irc/dcc `pkg-config --cflags glib-2.0`

do-extract:
	@${RM} -r ${WRKSRC}
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${DISTNAME}.so ${WRKSRC}/${DISTFILES}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/irssi/modules/lib
	${INSTALL_LIB} ${WRKSRC}/${DISTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/irssi/modules/lib

.include <bsd.port.mk>
