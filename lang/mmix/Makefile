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
	${INSTALL_PROGRAM} ${WRKSRC}/mmix ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmixal ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmmix ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mmotype ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mmconfig ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mmix ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mms ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.w ${DATADIR}
	${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/,} ${DATADIR}

.include <bsd.port.mk>
