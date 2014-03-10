# Created by: Jens Holmqvist <zparta@hispan.se>
# $FreeBSD$

PORTNAME=	irssi-fish
DISTVERSION=	1.00-RC5
CATEGORIES=	irc security
MASTER_SITES=	http://fish.secure.la/irssi/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/
DISTNAME=	FiSH-irssi.v${DISTVERSION}-source

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	An encryption plugin for irssi

BUILD_DEPENDS=	${LOCALBASE}/include/glib-2.0/glib.h:${PORTSDIR}/devel/glib20 \
		${LOCALBASE}/lib/libmiracl.a:${PORTSDIR}/math/miracl \
		${LOCALBASE}/include/irssi/src/common.h:${PORTSDIR}/irc/irssi
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

USES=		zip
USE_LDCONFIG=	yes

PLIST_FILES=	lib/irssi/modules/libfish.so
PORTDOCS=	FiSH-irssi.txt FiSH-irssi_History.txt

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
ALL_TARGET=	amd64
.endif

post-patch:
	@${GREP} -Rl 'fish[.]sekure[.]us' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -E \
		-e 's|fish[.]sekure[.]us|fish.secure.la|g'
	@${REINPLACE_CMD} -E \
		-e 's|gcc|${CC}|' \
		-e 's|-O2|${CFLAGS}|' \
		-e 's|-static||' \
		-e 's|-shared|-shared -fPIC -DPIC|' \
		-e 's|[$$][(]HOME[)]/glib-1.2.10|${LOCALBASE}/include/glib-2.0|' \
		-e 's|[$$][(]HOME[)]/irssi-0.8.9|${LOCALBASE}/include/irssi|' \
		-e 's|miracl.a|${LOCALBASE}/lib/libmiracl.a|' \
		-e 's|[$$]\(pwd\)|`pwd`|g' \
		-e 's|\@echo \"Press ENTER to continue or CTRL\+C to abort...\"\; read junk||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/mirdef.lnx/d' ${WRKSRC}/Makefile

do-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${PREFIX}/lib/irssi/modules
	${INSTALL_PROGRAM} ${WRKSRC}/libfish.so ${PREFIX}/lib/irssi/modules

.include <bsd.port.post.mk>
