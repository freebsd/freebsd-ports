# New ports collection makefile for:	irssi fish
# Date created:		Tue May 24 03:27:32 UTC 2005
# Whom:                 Jens Holmqvist <zparta@hispan.se>
#
# $FreeBSD$
#

PORTNAME=	irssi-fish
DISTVERSION=	0.99
CATEGORIES=	irc security
MASTER_SITES=	http://fish.sekure.us/irssi/
DISTNAME=	FiSH-irssi.v${DISTVERSION}-source

MAINTAINER=	pav@FreeBSD.org
COMMENT=	An encryption plugin for irssi

BUILD_DEPENDS=	${LOCALBASE}/include/glib-2.0/glib.h:${PORTSDIR}/devel/glib20 \
		${LOCALBASE}/lib/libmiracl.a:${PORTSDIR}/math/miracl \
		${NONEXISTENT}:${PORTSDIR}/irc/irssi:patch
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

USE_ZIP=	yes
USE_REINPLACE=	yes

PLIST_FILES=	lib/irssi/modules/libfish.so
PORTDOCS=	FiSH-irssi.txt FiSH-irssi_History.txt

IRSSI_WRKSRC!=	cd ${.CURDIR}/../irssi && ${MAKE} -V WRKSRC

post-patch:
	@${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -E -e 's|||' {} \;
	@${REINPLACE_CMD} -E \
		-e 's|gcc|${CC}|' \
		-e 's|-O2|${CFLAGS}|' \
		-e 's|-shared|-shared -fPIC -DPIC|' \
		-e 's|[$$][(]HOME[)]/glib-1.2.10|${LOCALBASE}/include/glib-2.0|' \
		-e 's|[$$][(]HOME[)]/irssi-0.8.9|${IRSSI_WRKSRC}|' \
		-e 's|miracl.a|${LOCALBASE}/lib/libmiracl.a|' \
		-e 's|\@echo \"Press ENTER to continue or CTRL\+C to abort...\"\; read junk||' \
		${WRKSRC}/Makefile

do-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${PREFIX}/lib/irssi/modules
	${INSTALL_PROGRAM} ${WRKSRC}/libfish.so ${PREFIX}/lib/irssi/modules

.include <bsd.port.mk>
