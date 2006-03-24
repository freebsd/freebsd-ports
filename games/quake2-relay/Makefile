# New ports collection makefile for:	Q2 Relay
# Date created:				23 Mar 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	relay
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL} http://freebsd.nsu.ru/distfiles/
MASTER_SITE_SUBDIR=	danfe
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	relay-${PORTVERSION}.src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II multi-view demo recording facility

USE_GMAKE=	yes
MAKE_ARGS=	MODE=release OBJ_DIR=. OUT_DIR=. Q2MODULE=game.so \
		QUAKE2_DIR="${Q2DIR}" BIN_DIR="${PREFIX}/bin" \
		CC="${CC}" CFLAGS="${CFLAGS}"

WRKSRC=		${WRKDIR}/relay-${PORTVERSION}

PLIST_FILES=	bin/democonv bin/dm2server \
		%%Q2DIR%%/release/game.so \
		%%Q2DIR%%/proxy/relay/game.so \
		%%Q2DIR%%/proxy/replay/game.so
PLIST_DIRS=	%%Q2DIR%%/proxy/replay %%Q2DIR%%/proxy/relay \
		%%Q2DIR%%/proxy %%Q2DIR%%/release
PORTDOCS=	FAQ README

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e 's/-ldl// ; /^include/d ; \
		s/cp -p/${INSTALL_PROGRAM}/' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/random/d' ${WRKSRC}/replay/rp_local.h
	${REINPLACE_CMD} -e 's,<malloc\.h>,<stdlib\.h>,' \
		${WRKSRC}/common/mem.c
	cd ${WRKSRC}/common && ${SH} -c 'for i in *.h; do \
		${ECHO_CMD} >> $${i}; done'
	# Reorganize #include's
	${ECHO_MSG} -e '35t30\n36d\nwq' | ${ED} -s ${WRKSRC}/common/net.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${WRKSRC}/README ${DOCSDIR}
.endif

ED?=	/bin/ed

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.post.mk>
