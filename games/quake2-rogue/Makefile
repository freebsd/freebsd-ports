PORTNAME=	rogue
PORTVERSION=	3.20
CATEGORIES=	games
MASTER_SITES=	IDSOFTWARE/quake2/source
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}src${PORTVERSION:S/.//}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II: Ground Zero (Rogue) official mission pack

NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	%%Q2DIR%%/${PORTNAME}/game.so
PLIST_DIRS=	%%Q2DIR%%/${PORTNAME}

do-extract:
	@cd ${WRKSRC} && uncompress -c ${DISTDIR}/${DISTFILES} | \
		${TAIL} +454 | ${SH}

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/#include <nan\.h>/d' ${WRKSRC}/g_local.h
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' ${WRKSRC}/q_shared.[ch]

do-install:
	@${MKDIR} ${STAGEDIR}${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/game.so ${STAGEDIR}${Q2DIR}/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
