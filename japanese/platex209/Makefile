# Created by: Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	platex209
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/
DISTNAME=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Old version of ASCII Japanese pLaTeX (based on LaTeX 2.09)

USE_TEX=	tetex ptex
WEB2CDIR=	${TEXMFDIR}/web2c/ptex
PLATEX209DIR=	${TEXMFDIR}/ptex/platex209

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} \
		MKTEXLSR=${MKTEXLSR} \
		WEB2CDIR=${WEB2CDIR} \
		PLATEX209DIR=${PLATEX209DIR}

NO_STAGE=	yes
do-build:
	@(cd ${WRKSRC}; ${LOCALBASE}/bin/ptex -ini 'plplain.tex\dump')

do-install:
	${MKDIR} ${PREFIX}/${PLATEX209DIR}/doc
	${MKDIR} ${PREFIX}/${PLATEX209DIR}/general
	${MKDIR} ${PREFIX}/${PLATEX209DIR}/sty
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/${PLATEX209DIR}
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/${PLATEX209DIR}/doc
	${INSTALL_DATA} ${WRKSRC}/*.tex ${PREFIX}/${PLATEX209DIR}/general
	${INSTALL_DATA} ${WRKSRC}/*.sty ${PREFIX}/${PLATEX209DIR}/sty
	${INSTALL_DATA} ${WRKSRC}/plplain.fmt ${PREFIX}/${WEB2CDIR}/platex209.fmt
	${LN} -f -s ${PREFIX}/bin/ptex ${PREFIX}/bin/platex209
	${MKTEXLSR}

.include <bsd.port.mk>
