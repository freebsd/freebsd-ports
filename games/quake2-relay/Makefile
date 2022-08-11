PORTNAME=	relay
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	LOCAL/danfe http://freebsd.nsu.ru/distfiles/
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	relay-${PORTVERSION}.src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II multi-view demo recording facility

LICENSE=	GPLv2

USES=		gmake
MAKE_ARGS=	MODE=release OBJ_DIR=. OUT_DIR=. Q2MODULE=game.so \
		QUAKE2_DIR="${STAGEDIR}${Q2DIR}" \
		BIN_DIR="${STAGEDIR}${PREFIX}/bin" \
		CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS} -fPIC" \
		LDFLAGS="${LDFLAGS} -lm"

WRKSRC=		${WRKDIR}/relay-${PORTVERSION}
PORTDOCS=	FAQ README

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.options.mk>

post-patch: .SILENT
	${REINPLACE_CMD} -e '/^include/d ; s/cp -p/${INSTALL_PROGRAM}/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/random/d' ${WRKSRC}/replay/rp_local.h
	${REINPLACE_CMD} -e 's,<malloc\.h>,<stdlib\.h>,' \
		${WRKSRC}/common/mem.c
	cd ${WRKSRC}/common && ${SH} -c 'for i in *.h; do \
		${ECHO_CMD} >> $${i}; done'
# Reorganize #include's (use /bin/ed to avoid a patch)
	${ECHO_CMD} -e '35t30\n36d\nwq' | ${ED} -s ${WRKSRC}/common/net.h
	${ECHO_CMD} -e '9t7\n10d\nwq' | ${ED} -s ${WRKSRC}/common/net.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

ED?=	/bin/ed

.include <bsd.port.mk>
