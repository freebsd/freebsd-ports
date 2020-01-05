# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	hpscat
PORTVERSION=	1.3.1
PORTEPOCH=	2
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.kaist.ac.kr/hangul/print/hpscat/ \
		ftp://ftp.kaist.ac.kr/hangul/print/hpscat/ \
		http://ftp.kaist.ac.kr/hangul/editor/ked/:ked \
		ftp://ftp.kaist.ac.kr/hangul/editor/ked/:ked \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
PKGNAMESUFFIX=	-jshin
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ked.tar.gz:ked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hangul Text Printing Utility

BROKEN=		unfetchable

RUN_DEPENDS=	hcode:korean/hcode

FONTDIR=	${PREFIX}/${FONTDIR_REL}
FONTDIR_REL=	share/fonts/ked-${PORTNAME}
FONTFILES=	Gotic Header Munjo MunjoBold PCMunjo
README_FILES=	README README.jshin README.jshin.ks
PLIST_FILES=	bin/hpscat bin/hpscat.bin
.for i in ${FONTFILES} ${README_FILES}
PLIST_FILES+=	${FONTDIR_REL}/${i}
.endfor
SUB_FILES=	hpscat.sh pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}
USES=		perl5

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/hpscat ${STAGEDIR}${PREFIX}/bin/hpscat.bin
	@${INSTALL_SCRIPT} ${WRKDIR}/hpscat.sh ${STAGEDIR}${PREFIX}/bin/hpscat
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${README_FILES}" ${STAGEDIR}${FONTDIR}
	@cd ${WRKDIR}/ked && ${COPYTREE_SHARE} "${FONTFILES}" ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
