# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmix
PORTVERSION=	20131017
CATEGORIES=	lang
MASTER_SITES=	http://mmix.cs.hm.edu/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	RISC computer designed by Donald E. Knuth

LICENSE=	mmix
LICENSE_NAME=	mmix license
LICENSE_FILE=	${FILESDIR}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	ctangle:devel/cweb

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
