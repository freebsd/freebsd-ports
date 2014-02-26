# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmix
PORTVERSION=	20110831
CATEGORIES=	lang
MASTER_SITES=	http://www-cs-faculty.stanford.edu/~knuth/programs/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	RISC computer designed by Donald E. Knuth

BUILD_DEPENDS=	ctangle:${PORTSDIR}/devel/cweb

NO_WRKSUBDIR=	yes
FILES=		mmix.1 mmix.mp silly.out silly.run

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmix ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmixal ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmmix ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmotype ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mmconfig ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mmix ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mms ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.w ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
