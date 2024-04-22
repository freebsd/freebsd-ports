PORTNAME=	awele
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	games tk
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake tk tar:tgz xorg
USE_XORG=	x11

MAKE_ARGS=	AWELE_DIR=${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/awelewish bin/xawele share/man/man6/xawele.6.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|; \
		 s|%%TK_VER%%|${TK_VER:S/.//}|; \
		 s|%%TCL_VER%%|${TCL_VER:S/.//}|; \
		 s|%%TK_INCLUDEDIR%%|${TK_INCLUDEDIR}|; \
		 s|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
