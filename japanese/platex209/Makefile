# New ports collection makefile for:	platex209-euc
# Date created:		01 Jan 1998
# Whom:			Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	platex209
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/
DISTNAME=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Old version of ASCII Japanese pLaTeX (based on LaTeX 2.09)

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-tetex
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-tetex

CONFLICTS=	ja-ptex-[0-9]*

MANUAL_PACKAGE_BUILD=	incompatible with other versions of platex209-*

TEXMF=		share/texmf
WEB2CDIR=	share/texmf/web2c-ptex
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

PLIST_SUB=	TEXMF=${TEXMF} \
		MKTEXLSR=${MKTEXLSR} \
		WEB2CDIR=${WEB2CDIR}

#pre-configure:
#	@(cd ${WRKSRC} ; \
#	  for i in * ; do ${MV} $$i $$i.orig ; nkf -e $$i.orig > $$i ; done)

do-build:
	@(cd ${WRKSRC}; ptex -ini 'plplain.tex \dump')

do-install:
	${MKDIR} ${PREFIX}/${TEXMF}/tex/platex209/doc
	${MKDIR} ${PREFIX}/${TEXMF}/tex/platex209/general
	${MKDIR} ${PREFIX}/${TEXMF}/tex/platex209/sty
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/${TEXMF}/tex/platex209
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/${TEXMF}/tex/platex209/doc
	${INSTALL_DATA} ${WRKSRC}/*.tex ${PREFIX}/${TEXMF}/tex/platex209/general
	${INSTALL_DATA} ${WRKSRC}/*.sty ${PREFIX}/${TEXMF}/tex/platex209/sty
	${INSTALL_DATA} ${WRKSRC}/plplain.fmt ${PREFIX}/${WEB2CDIR}/platex209.fmt
	${LN} -f -s ${PREFIX}/bin/ptex ${PREFIX}/bin/platex209
	${MKTEXLSR}

.include <bsd.port.mk>
