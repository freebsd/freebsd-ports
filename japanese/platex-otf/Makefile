# New ports collection makefile for:	platex-otf
# Date created:		21 Aug 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	platex-otf
PORTVERSION=	1.2.4
CATEGORIES=	japanese print
MASTER_SITES=	http://psitau.at.infoseek.co.jp/
DISTFILES=	otfstable${EXTRACT_SUFX} otfmanual.pdf
EXTRACT_ONLY=	otfstable${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A pLaTeX package for OpenType font support

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		mktexlsr:${PORTSDIR}/japanese/ptex-tetex \
		ovp2ovf-old:${PORTSDIR}/print/tex-omegaware-old \
		pltotf-ptex:${PORTSDIR}/japanese/ptex-tetex
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		platex:${PORTSDIR}/japanese/ptex-tetex \
		udvips:${PORTSDIR}/japanese/dvipsk \
		dvipdfmx:${PORTSDIR}/print/dvipdfmx

USE_ZIP=	YES
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR} \
		VFDIR=${VFDIR} TFMDIR=${TFMDIR} \
		DVIPSDIR=${DVIPSDIR} DVIPDFMDIR=${DVIPDFMDIR}
WRKSRC=		${WRKDIR}/otfstable
PLIST=		${WRKDIR}/pkg-plist
PKGMESSAGE_SUB=	DVIPSDIR=${DVIPSDIR_DST} \
		DVIPDFMDIR=${DVIPDFMDIR_DST}
PKGMESSAGE=	${WRKDIR}/pkg-message

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

CLASSDIR_SRC=	${WRKSRC}/sty
CLASSDIR_DST=	${TEXMFLOCAL}/ptex/platex/otf
CLASSFILES=	ajmacros.sty mlcid.sty mlutf.sty otf.sty redeffont.sty

OFMDIR_SRC=	${WRKSRC}/ofm
OFMDIR_DST=	${TEXMFLOCAL}/fonts/ofm/otf
OFMFILES=	otf-cjmr-h.ofm otf-cjgr-h.ofm otf-cjmb-h.ofm otf-cjgb-h.ofm \
		otf-cjmgr-h.ofm otf-cjml-h.ofm otf-cjmr-v.ofm otf-cjgr-v.ofm \
		otf-cjmb-v.ofm otf-cjgb-v.ofm otf-cjmgr-v.ofm otf-cjml-v.ofm \
		hiramin-w3-h.ofm hiramin-w3-v.ofm \
		hiramin-w6-h.ofm hiramin-w6-v.ofm \
		hirakaku-w3-h.ofm hirakaku-w3-v.ofm \
		hirakaku-w6-h.ofm hirakaku-w6-v.ofm \
		hiramaru-w4-h.ofm hiramaru-w4-v.ofm

TFMDIR_SRC=	${WRKSRC}/tfm
TFMDIR_DST=	${TEXMFLOCAL}/fonts/tfm/otf
TFMFILES=	cidcgr0-h.tfm cidcgr0-v.tfm cidcgr1-h.tfm \
		cidcgr1-v.tfm cidcgr2-h.tfm cidcgr2-v.tfm \
		cidcgr3-h.tfm cidcgr3-v.tfm cidcgr4-h.tfm \
		cidcgr4-v.tfm cidcgr5-h.tfm cidcgr5-v.tfm \
		cidcgr6-h.tfm cidcgr6-v.tfm cidcgr7-h.tfm \
		cidcgr7-v.tfm cidcmr0-h.tfm cidcmr0-v.tfm \
		cidcmr1-h.tfm cidcmr1-v.tfm cidcmr2-h.tfm \
		cidcmr2-v.tfm cidcmr3-h.tfm cidcmr3-v.tfm \
		cidcmr4-h.tfm cidcmr4-v.tfm cidcmr5-h.tfm \
		cidcmr5-v.tfm cidcmr6-h.tfm cidcmr6-v.tfm \
		cidcmr7-h.tfm cidcmr7-v.tfm cidjgb0-h.tfm \
		cidjgb0-v.tfm cidjgb1-h.tfm cidjgb1-v.tfm \
		cidjgb2-h.tfm cidjgb2-v.tfm cidjgb3-h.tfm \
		cidjgb3-v.tfm cidjgb4-h.tfm cidjgb4-v.tfm \
		cidjgr0-h.tfm cidjgr0-v.tfm cidjgr1-h.tfm \
		cidjgr1-v.tfm cidjgr2-h.tfm cidjgr2-v.tfm \
		cidjgr3-h.tfm cidjgr3-v.tfm cidjgr4-h.tfm \
		cidjgr4-v.tfm cidjmb0-h.tfm cidjmb0-v.tfm \
		cidjmb1-h.tfm cidjmb1-v.tfm cidjmb2-h.tfm \
		cidjmb2-v.tfm cidjmb3-h.tfm cidjmb3-v.tfm \
		cidjmb4-h.tfm cidjmb4-v.tfm cidjmgr0-h.tfm \
		cidjmgr0-v.tfm cidjmgr1-h.tfm cidjmgr1-v.tfm \
		cidjmgr2-h.tfm cidjmgr2-v.tfm cidjmgr3-h.tfm \
		cidjmgr3-v.tfm cidjmgr4-h.tfm cidjmgr4-v.tfm \
		cidjml0-h.tfm cidjml0-v.tfm cidjml1-h.tfm \
		cidjml1-v.tfm cidjml2-h.tfm cidjml2-v.tfm \
		cidjml3-h.tfm cidjml3-v.tfm cidjml4-h.tfm \
		cidjml4-v.tfm cidjmr0-h.tfm cidjmr0-v.tfm \
		cidjmr1-h.tfm cidjmr1-v.tfm cidjmr2-h.tfm \
		cidjmr2-v.tfm cidjmr3-h.tfm cidjmr3-v.tfm \
		cidjmr4-h.tfm cidjmr4-v.tfm cidkgr0-h.tfm \
		cidkgr0-v.tfm cidkgr1-h.tfm cidkgr1-v.tfm \
		cidkgr2-h.tfm cidkgr2-v.tfm cidkgr3-h.tfm \
		cidkgr3-v.tfm cidkgr4-h.tfm cidkgr4-v.tfm \
		cidkmr0-h.tfm cidkmr0-v.tfm cidkmr1-h.tfm \
		cidkmr1-v.tfm cidkmr2-h.tfm cidkmr2-v.tfm \
		cidkmr3-h.tfm cidkmr3-v.tfm cidkmr4-h.tfm \
		cidkmr4-v.tfm cidtgr0-h.tfm cidtgr0-v.tfm \
		cidtgr1-h.tfm cidtgr1-v.tfm cidtgr2-h.tfm \
		cidtgr2-v.tfm cidtgr3-h.tfm cidtgr3-v.tfm \
		cidtgr4-h.tfm cidtgr4-v.tfm cidtmr0-h.tfm \
		cidtmr0-v.tfm cidtmr1-h.tfm cidtmr1-v.tfm \
		cidtmr2-h.tfm cidtmr2-v.tfm cidtmr3-h.tfm \
		cidtmr3-v.tfm cidtmr4-h.tfm cidtmr4-v.tfm \
		expgothb-h.tfm expgothb-v.tfm expgothr-h.tfm \
		expgothr-v.tfm expmgothr-h.tfm expmgothr-v.tfm \
		expminb-h.tfm expminb-v.tfm expminl-h.tfm \
		expminl-v.tfm expminr-h.tfm expminr-v.tfm \
		hgothb-h.tfm hgothb-v.tfm hgotheb-h.tfm \
		hgotheb-v.tfm hgothr-h.tfm hgothr-v.tfm \
		hirakaku-w3-h.tfm hirakaku-w3-v.tfm hirakaku-w6-h.tfm \
		hirakaku-w6-v.tfm hiramaru-w4-h.tfm hiramaru-w4-v.tfm \
		hiramin-w3-h.tfm hiramin-w3-v.tfm hiramin-w6-h.tfm \
		hiramin-w6-v.tfm hmgothr-h.tfm hmgothr-v.tfm \
		hminb-h.tfm hminb-v.tfm hminl-h.tfm \
		hminl-v.tfm hminr-h.tfm hminr-v.tfm \
		nmlgothb-h.tfm nmlgothb-v.tfm nmlgotheb-h.tfm \
		nmlgotheb-v.tfm nmlgothr-h.tfm nmlgothr-v.tfm \
		nmlmgothr-h.tfm nmlmgothr-v.tfm nmlminb-h.tfm \
		nmlminb-v.tfm nmlminl-h.tfm nmlminl-v.tfm \
		nmlminr-h.tfm nmlminr-v.tfm otf-ccgr-h.tfm \
		otf-ccgr-v.tfm otf-ccmr-h.tfm otf-ccmr-v.tfm \
		otf-cjgb-h.tfm otf-cjgb-v.tfm otf-cjgr-h.tfm \
		otf-cjgr-v.tfm otf-cjmb-h.tfm otf-cjmb-v.tfm \
		otf-cjmgr-h.tfm otf-cjmgr-v.tfm otf-cjml-h.tfm \
		otf-cjml-v.tfm otf-cjmr-h.tfm otf-cjmr-v.tfm \
		otf-ckgr-h.tfm otf-ckgr-v.tfm otf-ckmr-h.tfm \
		otf-ckmr-v.tfm otf-ctgr-h.tfm otf-ctgr-v.tfm \
		otf-ctmr-h.tfm otf-ctmr-v.tfm otf-ucgr-h.tfm \
		otf-ucgr-v.tfm otf-ucmr-h.tfm otf-ucmr-v.tfm \
		otf-ujgb-h.tfm otf-ujgb-v.tfm otf-ujgr-h.tfm \
		otf-ujgr-v.tfm otf-ujmb-h.tfm otf-ujmb-v.tfm \
		otf-ujmgr-h.tfm otf-ujmgr-v.tfm otf-ujml-h.tfm \
		otf-ujml-v.tfm otf-ujmr-h.tfm otf-ujmr-v.tfm \
		otf-ukgr-h.tfm otf-ukgr-v.tfm otf-ukmr-h.tfm \
		otf-ukmr-v.tfm otf-utgr-h.tfm otf-utgr-v.tfm \
		otf-utmr-h.tfm otf-utmr-v.tfm phirakakuw3-h.tfm \
		phirakakuw3-v.tfm phirakakuw6-h.tfm phirakakuw6-v.tfm \
		phiramaruw4-h.tfm phiramaruw4-v.tfm phiraminw3-h.tfm \
		phiraminw3-v.tfm phiraminw6-h.tfm phiraminw6-v.tfm \
		rubygothb-h.tfm rubygothb-v.tfm rubygothr-h.tfm \
		rubygothr-v.tfm rubymgothr-h.tfm rubymgothr-v.tfm \
		rubyminb-h.tfm rubyminb-v.tfm rubyminl-h.tfm \
		rubyminl-v.tfm rubyminr-h.tfm rubyminr-v.tfm \
		utfcgr0-h.tfm utfcgr0-v.tfm utfcgr1-h.tfm \
		utfcgr1-v.tfm utfcgr2-h.tfm utfcgr2-v.tfm \
		utfcgr3-h.tfm utfcgr3-v.tfm utfcgr4-h.tfm \
		utfcgr4-v.tfm utfcgr5-h.tfm utfcgr5-v.tfm \
		utfcgr6-h.tfm utfcgr6-v.tfm utfcgr7-h.tfm \
		utfcgr7-v.tfm utfcgr8-h.tfm utfcgr8-v.tfm \
		utfcgr9-h.tfm utfcgr9-v.tfm utfcgra-h.tfm \
		utfcgra-v.tfm utfcgrb-h.tfm utfcgrb-v.tfm \
		utfcgrc-h.tfm utfcgrc-v.tfm utfcgrd-h.tfm \
		utfcgrd-v.tfm utfcgre-h.tfm utfcgre-v.tfm \
		utfcgrf-h.tfm utfcgrf-v.tfm utfcmr0-h.tfm \
		utfcmr0-v.tfm utfcmr1-h.tfm utfcmr1-v.tfm \
		utfcmr2-h.tfm utfcmr2-v.tfm utfcmr3-h.tfm \
		utfcmr3-v.tfm utfcmr4-h.tfm utfcmr4-v.tfm \
		utfcmr5-h.tfm utfcmr5-v.tfm utfcmr6-h.tfm \
		utfcmr6-v.tfm utfcmr7-h.tfm utfcmr7-v.tfm \
		utfcmr8-h.tfm utfcmr8-v.tfm utfcmr9-h.tfm \
		utfcmr9-v.tfm utfcmra-h.tfm utfcmra-v.tfm \
		utfcmrb-h.tfm utfcmrb-v.tfm utfcmrc-h.tfm \
		utfcmrc-v.tfm utfcmrd-h.tfm utfcmrd-v.tfm \
		utfcmre-h.tfm utfcmre-v.tfm utfcmrf-h.tfm \
		utfcmrf-v.tfm utfgr0-h.tfm utfgr0-v.tfm \
		utfgr1-h.tfm utfgr1-v.tfm utfgr2-h.tfm \
		utfgr2-v.tfm utfgr3-h.tfm utfgr3-v.tfm \
		utfgr4-h.tfm utfgr4-v.tfm utfgr5-h.tfm \
		utfgr5-v.tfm utfgr6-h.tfm utfgr6-v.tfm \
		utfgr7-h.tfm utfgr7-v.tfm utfgr8-h.tfm \
		utfgr8-v.tfm utfgr9-h.tfm utfgr9-v.tfm \
		utfgra-h.tfm utfgra-v.tfm utfgrb-h.tfm \
		utfgrb-v.tfm utfgrc-h.tfm utfgrc-v.tfm \
		utfgrd-h.tfm utfgrd-v.tfm utfgre-h.tfm \
		utfgre-v.tfm utfgrf-h.tfm utfgrf-v.tfm \
		utfjgb0-h.tfm utfjgb0-v.tfm utfjgb1-h.tfm \
		utfjgb1-v.tfm utfjgb2-h.tfm utfjgb2-v.tfm \
		utfjgb3-h.tfm utfjgb3-v.tfm utfjgb4-h.tfm \
		utfjgb4-v.tfm utfjgb5-h.tfm utfjgb5-v.tfm \
		utfjgb6-h.tfm utfjgb6-v.tfm utfjgb7-h.tfm \
		utfjgb7-v.tfm utfjgb8-h.tfm utfjgb8-v.tfm \
		utfjgb9-h.tfm utfjgb9-v.tfm utfjgba-h.tfm \
		utfjgba-v.tfm utfjgbb-h.tfm utfjgbb-v.tfm \
		utfjgbc-h.tfm utfjgbc-v.tfm utfjgbd-h.tfm \
		utfjgbd-v.tfm utfjgbe-h.tfm utfjgbe-v.tfm \
		utfjgbf-h.tfm utfjgbf-v.tfm utfjgr0-h.tfm \
		utfjgr0-v.tfm utfjgr1-h.tfm utfjgr1-v.tfm \
		utfjgr2-h.tfm utfjgr2-v.tfm utfjgr3-h.tfm \
		utfjgr3-v.tfm utfjgr4-h.tfm utfjgr4-v.tfm \
		utfjgr5-h.tfm utfjgr5-v.tfm utfjgr6-h.tfm \
		utfjgr6-v.tfm utfjgr7-h.tfm utfjgr7-v.tfm \
		utfjgr8-h.tfm utfjgr8-v.tfm utfjgr9-h.tfm \
		utfjgr9-v.tfm utfjgra-h.tfm utfjgra-v.tfm \
		utfjgrb-h.tfm utfjgrb-v.tfm utfjgrc-h.tfm \
		utfjgrc-v.tfm utfjgrd-h.tfm utfjgrd-v.tfm \
		utfjgre-h.tfm utfjgre-v.tfm utfjgrf-h.tfm \
		utfjgrf-v.tfm utfjmb0-h.tfm utfjmb0-v.tfm \
		utfjmb1-h.tfm utfjmb1-v.tfm utfjmb2-h.tfm \
		utfjmb2-v.tfm utfjmb3-h.tfm utfjmb3-v.tfm \
		utfjmb4-h.tfm utfjmb4-v.tfm utfjmb5-h.tfm \
		utfjmb5-v.tfm utfjmb6-h.tfm utfjmb6-v.tfm \
		utfjmb7-h.tfm utfjmb7-v.tfm utfjmb8-h.tfm \
		utfjmb8-v.tfm utfjmb9-h.tfm utfjmb9-v.tfm \
		utfjmba-h.tfm utfjmba-v.tfm utfjmbb-h.tfm \
		utfjmbb-v.tfm utfjmbc-h.tfm utfjmbc-v.tfm \
		utfjmbd-h.tfm utfjmbd-v.tfm utfjmbe-h.tfm \
		utfjmbe-v.tfm utfjmbf-h.tfm utfjmbf-v.tfm \
		utfjmgr0-h.tfm utfjmgr0-v.tfm utfjmgr1-h.tfm \
		utfjmgr1-v.tfm utfjmgr2-h.tfm utfjmgr2-v.tfm \
		utfjmgr3-h.tfm utfjmgr3-v.tfm utfjmgr4-h.tfm \
		utfjmgr4-v.tfm utfjmgr5-h.tfm utfjmgr5-v.tfm \
		utfjmgr6-h.tfm utfjmgr6-v.tfm utfjmgr7-h.tfm \
		utfjmgr7-v.tfm utfjmgr8-h.tfm utfjmgr8-v.tfm \
		utfjmgr9-h.tfm utfjmgr9-v.tfm utfjmgra-h.tfm \
		utfjmgra-v.tfm utfjmgrb-h.tfm utfjmgrb-v.tfm \
		utfjmgrc-h.tfm utfjmgrc-v.tfm utfjmgrd-h.tfm \
		utfjmgrd-v.tfm utfjmgre-h.tfm utfjmgre-v.tfm \
		utfjmgrf-h.tfm utfjmgrf-v.tfm utfjml0-h.tfm \
		utfjml0-v.tfm utfjml1-h.tfm utfjml1-v.tfm \
		utfjml2-h.tfm utfjml2-v.tfm utfjml3-h.tfm \
		utfjml3-v.tfm utfjml4-h.tfm utfjml4-v.tfm \
		utfjml5-h.tfm utfjml5-v.tfm utfjml6-h.tfm \
		utfjml6-v.tfm utfjml7-h.tfm utfjml7-v.tfm \
		utfjml8-h.tfm utfjml8-v.tfm utfjml9-h.tfm \
		utfjml9-v.tfm utfjmla-h.tfm utfjmla-v.tfm \
		utfjmlb-h.tfm utfjmlb-v.tfm utfjmlc-h.tfm \
		utfjmlc-v.tfm utfjmld-h.tfm utfjmld-v.tfm \
		utfjmle-h.tfm utfjmle-v.tfm utfjmlf-h.tfm \
		utfjmlf-v.tfm utfjmr0-h.tfm utfjmr0-v.tfm \
		utfjmr1-h.tfm utfjmr1-v.tfm utfjmr2-h.tfm \
		utfjmr2-v.tfm utfjmr3-h.tfm utfjmr3-v.tfm \
		utfjmr4-h.tfm utfjmr4-v.tfm utfjmr5-h.tfm \
		utfjmr5-v.tfm utfjmr6-h.tfm utfjmr6-v.tfm \
		utfjmr7-h.tfm utfjmr7-v.tfm utfjmr8-h.tfm \
		utfjmr8-v.tfm utfjmr9-h.tfm utfjmr9-v.tfm \
		utfjmra-h.tfm utfjmra-v.tfm utfjmrb-h.tfm \
		utfjmrb-v.tfm utfjmrc-h.tfm utfjmrc-v.tfm \
		utfjmrd-h.tfm utfjmrd-v.tfm utfjmre-h.tfm \
		utfjmre-v.tfm utfjmrf-h.tfm utfjmrf-v.tfm \
		utfkgr0-h.tfm utfkgr0-v.tfm utfkgr1-h.tfm \
		utfkgr1-v.tfm utfkgr2-h.tfm utfkgr2-v.tfm \
		utfkgr3-h.tfm utfkgr3-v.tfm utfkgr4-h.tfm \
		utfkgr4-v.tfm utfkgr5-h.tfm utfkgr5-v.tfm \
		utfkgr6-h.tfm utfkgr6-v.tfm utfkgr7-h.tfm \
		utfkgr7-v.tfm utfkgr8-h.tfm utfkgr8-v.tfm \
		utfkgr9-h.tfm utfkgr9-v.tfm utfkgra-h.tfm \
		utfkgra-v.tfm utfkgrb-h.tfm utfkgrb-v.tfm \
		utfkgrc-h.tfm utfkgrc-v.tfm utfkgrd-h.tfm \
		utfkgrd-v.tfm utfkgre-h.tfm utfkgre-v.tfm \
		utfkgrf-h.tfm utfkgrf-v.tfm utfkmr0-h.tfm \
		utfkmr0-v.tfm utfkmr1-h.tfm utfkmr1-v.tfm \
		utfkmr2-h.tfm utfkmr2-v.tfm utfkmr3-h.tfm \
		utfkmr3-v.tfm utfkmr4-h.tfm utfkmr4-v.tfm \
		utfkmr5-h.tfm utfkmr5-v.tfm utfkmr6-h.tfm \
		utfkmr6-v.tfm utfkmr7-h.tfm utfkmr7-v.tfm \
		utfkmr8-h.tfm utfkmr8-v.tfm utfkmr9-h.tfm \
		utfkmr9-v.tfm utfkmra-h.tfm utfkmra-v.tfm \
		utfkmrb-h.tfm utfkmrb-v.tfm utfkmrc-h.tfm \
		utfkmrc-v.tfm utfkmrd-h.tfm utfkmrd-v.tfm \
		utfkmre-h.tfm utfkmre-v.tfm utfkmrf-h.tfm \
		utfkmrf-v.tfm utfmr0-h.tfm utfmr0-v.tfm \
		utfmr1-h.tfm utfmr1-v.tfm utfmr2-h.tfm \
		utfmr2-v.tfm utfmr3-h.tfm utfmr3-v.tfm \
		utfmr4-h.tfm utfmr4-v.tfm utfmr5-h.tfm \
		utfmr5-v.tfm utfmr6-h.tfm utfmr6-v.tfm \
		utfmr7-h.tfm utfmr7-v.tfm utfmr8-h.tfm \
		utfmr8-v.tfm utfmr9-h.tfm utfmr9-v.tfm \
		utfmra-h.tfm utfmra-v.tfm utfmrb-h.tfm \
		utfmrb-v.tfm utfmrc-h.tfm utfmrc-v.tfm \
		utfmrd-h.tfm utfmrd-v.tfm utfmre-h.tfm \
		utfmre-v.tfm utfmrf-h.tfm utfmrf-v.tfm \
		utftgr0-h.tfm utftgr0-v.tfm utftgr1-h.tfm \
		utftgr1-v.tfm utftgr2-h.tfm utftgr2-v.tfm \
		utftgr3-h.tfm utftgr3-v.tfm utftgr4-h.tfm \
		utftgr4-v.tfm utftgr5-h.tfm utftgr5-v.tfm \
		utftgr6-h.tfm utftgr6-v.tfm utftgr7-h.tfm \
		utftgr7-v.tfm utftgr8-h.tfm utftgr8-v.tfm \
		utftgr9-h.tfm utftgr9-v.tfm utftgra-h.tfm \
		utftgra-v.tfm utftgrb-h.tfm utftgrb-v.tfm \
		utftgrc-h.tfm utftgrc-v.tfm utftgrd-h.tfm \
		utftgrd-v.tfm utftgre-h.tfm utftgre-v.tfm \
		utftgrf-h.tfm utftgrf-v.tfm utftmr0-h.tfm \
		utftmr0-v.tfm utftmr1-h.tfm utftmr1-v.tfm \
		utftmr2-h.tfm utftmr2-v.tfm utftmr3-h.tfm \
		utftmr3-v.tfm utftmr4-h.tfm utftmr4-v.tfm \
		utftmr5-h.tfm utftmr5-v.tfm utftmr6-h.tfm \
		utftmr6-v.tfm utftmr7-h.tfm utftmr7-v.tfm \
		utftmr8-h.tfm utftmr8-v.tfm utftmr9-h.tfm \
		utftmr9-v.tfm utftmra-h.tfm utftmra-v.tfm \
		utftmrb-h.tfm utftmrb-v.tfm utftmrc-h.tfm \
		utftmrc-v.tfm utftmrd-h.tfm utftmrd-v.tfm \
		utftmre-h.tfm utftmre-v.tfm utftmrf-h.tfm \
		utftmrf-v.tfm

VFDIR_SRC=	${WRKSRC}/vf
VFDIR_DST=	${TEXMFLOCAL}/fonts/vf/otf
VFFILES=	cidcgr0-h.vf cidcgr0-v.vf cidcgr1-h.vf \
		cidcgr1-v.vf cidcgr2-h.vf cidcgr2-v.vf \
		cidcgr3-h.vf cidcgr3-v.vf cidcgr4-h.vf \
		cidcgr4-v.vf cidcgr5-h.vf cidcgr5-v.vf \
		cidcgr6-h.vf cidcgr6-v.vf cidcgr7-h.vf \
		cidcgr7-v.vf cidcmr0-h.vf cidcmr0-v.vf \
		cidcmr1-h.vf cidcmr1-v.vf cidcmr2-h.vf \
		cidcmr2-v.vf cidcmr3-h.vf cidcmr3-v.vf \
		cidcmr4-h.vf cidcmr4-v.vf cidcmr5-h.vf \
		cidcmr5-v.vf cidcmr6-h.vf cidcmr6-v.vf \
		cidcmr7-h.vf cidcmr7-v.vf cidjgb0-h.vf \
		cidjgb0-v.vf cidjgb1-h.vf cidjgb1-v.vf \
		cidjgb2-h.vf cidjgb2-v.vf cidjgb3-h.vf \
		cidjgb3-v.vf cidjgb4-h.vf cidjgb4-v.vf \
		cidjgr0-h.vf cidjgr0-v.vf cidjgr1-h.vf \
		cidjgr1-v.vf cidjgr2-h.vf cidjgr2-v.vf \
		cidjgr3-h.vf cidjgr3-v.vf cidjgr4-h.vf \
		cidjgr4-v.vf cidjmb0-h.vf cidjmb0-v.vf \
		cidjmb1-h.vf cidjmb1-v.vf cidjmb2-h.vf \
		cidjmb2-v.vf cidjmb3-h.vf cidjmb3-v.vf \
		cidjmb4-h.vf cidjmb4-v.vf cidjmgr0-h.vf \
		cidjmgr0-v.vf cidjmgr1-h.vf cidjmgr1-v.vf \
		cidjmgr2-h.vf cidjmgr2-v.vf cidjmgr3-h.vf \
		cidjmgr3-v.vf cidjmgr4-h.vf cidjmgr4-v.vf \
		cidjml0-h.vf cidjml0-v.vf cidjml1-h.vf \
		cidjml1-v.vf cidjml2-h.vf cidjml2-v.vf \
		cidjml3-h.vf cidjml3-v.vf cidjml4-h.vf \
		cidjml4-v.vf cidjmr0-h.vf cidjmr0-v.vf \
		cidjmr1-h.vf cidjmr1-v.vf cidjmr2-h.vf \
		cidjmr2-v.vf cidjmr3-h.vf cidjmr3-v.vf \
		cidjmr4-h.vf cidjmr4-v.vf cidkgr0-h.vf \
		cidkgr0-v.vf cidkgr1-h.vf cidkgr1-v.vf \
		cidkgr2-h.vf cidkgr2-v.vf cidkgr3-h.vf \
		cidkgr3-v.vf cidkgr4-h.vf cidkgr4-v.vf \
		cidkmr0-h.vf cidkmr0-v.vf cidkmr1-h.vf \
		cidkmr1-v.vf cidkmr2-h.vf cidkmr2-v.vf \
		cidkmr3-h.vf cidkmr3-v.vf cidkmr4-h.vf \
		cidkmr4-v.vf cidtgr0-h.vf cidtgr0-v.vf \
		cidtgr1-h.vf cidtgr1-v.vf cidtgr2-h.vf \
		cidtgr2-v.vf cidtgr3-h.vf cidtgr3-v.vf \
		cidtgr4-h.vf cidtgr4-v.vf cidtmr0-h.vf \
		cidtmr0-v.vf cidtmr1-h.vf cidtmr1-v.vf \
		cidtmr2-h.vf cidtmr2-v.vf cidtmr3-h.vf \
		cidtmr3-v.vf cidtmr4-h.vf cidtmr4-v.vf \
		expgothb-h.vf expgothb-v.vf expgothr-h.vf \
		expgothr-v.vf expmgothr-h.vf expmgothr-v.vf \
		expminb-h.vf expminb-v.vf expminl-h.vf \
		expminl-v.vf expminr-h.vf expminr-v.vf \
		nmlgothb-h.vf nmlgothb-v.vf nmlgotheb-h.vf \
		nmlgotheb-v.vf nmlgothr-h.vf nmlgothr-v.vf \
		nmlmgothr-h.vf nmlmgothr-v.vf nmlminb-h.vf \
		nmlminb-v.vf nmlminl-h.vf nmlminl-v.vf \
		nmlminr-h.vf nmlminr-v.vf phirakakuw3-h.vf \
		phirakakuw3-v.vf phirakakuw6-h.vf phirakakuw6-v.vf \
		phiramaruw4-h.vf phiramaruw4-v.vf phiraminw3-h.vf \
		phiraminw3-v.vf phiraminw6-h.vf phiraminw6-v.vf \
		rubygothb-h.vf rubygothb-v.vf rubygothr-h.vf \
		rubygothr-v.vf rubymgothr-h.vf rubymgothr-v.vf \
		rubyminb-h.vf rubyminb-v.vf rubyminl-h.vf \
		rubyminl-v.vf rubyminr-h.vf rubyminr-v.vf \
		utfcgr0-h.vf utfcgr0-v.vf utfcgr1-h.vf \
		utfcgr1-v.vf utfcgr2-h.vf utfcgr2-v.vf \
		utfcgr3-h.vf utfcgr3-v.vf utfcgr4-h.vf \
		utfcgr4-v.vf utfcgr5-h.vf utfcgr5-v.vf \
		utfcgr6-h.vf utfcgr6-v.vf utfcgr7-h.vf \
		utfcgr7-v.vf utfcgr8-h.vf utfcgr8-v.vf \
		utfcgr9-h.vf utfcgr9-v.vf utfcgra-h.vf \
		utfcgra-v.vf utfcgrb-h.vf utfcgrb-v.vf \
		utfcgrc-h.vf utfcgrc-v.vf utfcgrd-h.vf \
		utfcgrd-v.vf utfcgre-h.vf utfcgre-v.vf \
		utfcgrf-h.vf utfcgrf-v.vf utfcmr0-h.vf \
		utfcmr0-v.vf utfcmr1-h.vf utfcmr1-v.vf \
		utfcmr2-h.vf utfcmr2-v.vf utfcmr3-h.vf \
		utfcmr3-v.vf utfcmr4-h.vf utfcmr4-v.vf \
		utfcmr5-h.vf utfcmr5-v.vf utfcmr6-h.vf \
		utfcmr6-v.vf utfcmr7-h.vf utfcmr7-v.vf \
		utfcmr8-h.vf utfcmr8-v.vf utfcmr9-h.vf \
		utfcmr9-v.vf utfcmra-h.vf utfcmra-v.vf \
		utfcmrb-h.vf utfcmrb-v.vf utfcmrc-h.vf \
		utfcmrc-v.vf utfcmrd-h.vf utfcmrd-v.vf \
		utfcmre-h.vf utfcmre-v.vf utfcmrf-h.vf \
		utfcmrf-v.vf utfgr0-h.vf utfgr0-v.vf \
		utfgr1-h.vf utfgr1-v.vf utfgr2-h.vf \
		utfgr2-v.vf utfgr3-h.vf utfgr3-v.vf \
		utfgr4-h.vf utfgr4-v.vf utfgr5-h.vf \
		utfgr5-v.vf utfgr6-h.vf utfgr6-v.vf \
		utfgr7-h.vf utfgr7-v.vf utfgr8-h.vf \
		utfgr8-v.vf utfgr9-h.vf utfgr9-v.vf \
		utfgra-h.vf utfgra-v.vf utfgrb-h.vf \
		utfgrb-v.vf utfgrc-h.vf utfgrc-v.vf \
		utfgrd-h.vf utfgrd-v.vf utfgre-h.vf \
		utfgre-v.vf utfgrf-h.vf utfgrf-v.vf \
		utfjgb0-h.vf utfjgb0-v.vf utfjgb1-h.vf \
		utfjgb1-v.vf utfjgb2-h.vf utfjgb2-v.vf \
		utfjgb3-h.vf utfjgb3-v.vf utfjgb4-h.vf \
		utfjgb4-v.vf utfjgb5-h.vf utfjgb5-v.vf \
		utfjgb6-h.vf utfjgb6-v.vf utfjgb7-h.vf \
		utfjgb7-v.vf utfjgb8-h.vf utfjgb8-v.vf \
		utfjgb9-h.vf utfjgb9-v.vf utfjgba-h.vf \
		utfjgba-v.vf utfjgbb-h.vf utfjgbb-v.vf \
		utfjgbc-h.vf utfjgbc-v.vf utfjgbd-h.vf \
		utfjgbd-v.vf utfjgbe-h.vf utfjgbe-v.vf \
		utfjgbf-h.vf utfjgbf-v.vf utfjgr0-h.vf \
		utfjgr0-v.vf utfjgr1-h.vf utfjgr1-v.vf \
		utfjgr2-h.vf utfjgr2-v.vf utfjgr3-h.vf \
		utfjgr3-v.vf utfjgr4-h.vf utfjgr4-v.vf \
		utfjgr5-h.vf utfjgr5-v.vf utfjgr6-h.vf \
		utfjgr6-v.vf utfjgr7-h.vf utfjgr7-v.vf \
		utfjgr8-h.vf utfjgr8-v.vf utfjgr9-h.vf \
		utfjgr9-v.vf utfjgra-h.vf utfjgra-v.vf \
		utfjgrb-h.vf utfjgrb-v.vf utfjgrc-h.vf \
		utfjgrc-v.vf utfjgrd-h.vf utfjgrd-v.vf \
		utfjgre-h.vf utfjgre-v.vf utfjgrf-h.vf \
		utfjgrf-v.vf utfjmb0-h.vf utfjmb0-v.vf \
		utfjmb1-h.vf utfjmb1-v.vf utfjmb2-h.vf \
		utfjmb2-v.vf utfjmb3-h.vf utfjmb3-v.vf \
		utfjmb4-h.vf utfjmb4-v.vf utfjmb5-h.vf \
		utfjmb5-v.vf utfjmb6-h.vf utfjmb6-v.vf \
		utfjmb7-h.vf utfjmb7-v.vf utfjmb8-h.vf \
		utfjmb8-v.vf utfjmb9-h.vf utfjmb9-v.vf \
		utfjmba-h.vf utfjmba-v.vf utfjmbb-h.vf \
		utfjmbb-v.vf utfjmbc-h.vf utfjmbc-v.vf \
		utfjmbd-h.vf utfjmbd-v.vf utfjmbe-h.vf \
		utfjmbe-v.vf utfjmbf-h.vf utfjmbf-v.vf \
		utfjmgr0-h.vf utfjmgr0-v.vf utfjmgr1-h.vf \
		utfjmgr1-v.vf utfjmgr2-h.vf utfjmgr2-v.vf \
		utfjmgr3-h.vf utfjmgr3-v.vf utfjmgr4-h.vf \
		utfjmgr4-v.vf utfjmgr5-h.vf utfjmgr5-v.vf \
		utfjmgr6-h.vf utfjmgr6-v.vf utfjmgr7-h.vf \
		utfjmgr7-v.vf utfjmgr8-h.vf utfjmgr8-v.vf \
		utfjmgr9-h.vf utfjmgr9-v.vf utfjmgra-h.vf \
		utfjmgra-v.vf utfjmgrb-h.vf utfjmgrb-v.vf \
		utfjmgrc-h.vf utfjmgrc-v.vf utfjmgrd-h.vf \
		utfjmgrd-v.vf utfjmgre-h.vf utfjmgre-v.vf \
		utfjmgrf-h.vf utfjmgrf-v.vf utfjml0-h.vf \
		utfjml0-v.vf utfjml1-h.vf utfjml1-v.vf \
		utfjml2-h.vf utfjml2-v.vf utfjml3-h.vf \
		utfjml3-v.vf utfjml4-h.vf utfjml4-v.vf \
		utfjml5-h.vf utfjml5-v.vf utfjml6-h.vf \
		utfjml6-v.vf utfjml7-h.vf utfjml7-v.vf \
		utfjml8-h.vf utfjml8-v.vf utfjml9-h.vf \
		utfjml9-v.vf utfjmla-h.vf utfjmla-v.vf \
		utfjmlb-h.vf utfjmlb-v.vf utfjmlc-h.vf \
		utfjmlc-v.vf utfjmld-h.vf utfjmld-v.vf \
		utfjmle-h.vf utfjmle-v.vf utfjmlf-h.vf \
		utfjmlf-v.vf utfjmr0-h.vf utfjmr0-v.vf \
		utfjmr1-h.vf utfjmr1-v.vf utfjmr2-h.vf \
		utfjmr2-v.vf utfjmr3-h.vf utfjmr3-v.vf \
		utfjmr4-h.vf utfjmr4-v.vf utfjmr5-h.vf \
		utfjmr5-v.vf utfjmr6-h.vf utfjmr6-v.vf \
		utfjmr7-h.vf utfjmr7-v.vf utfjmr8-h.vf \
		utfjmr8-v.vf utfjmr9-h.vf utfjmr9-v.vf \
		utfjmra-h.vf utfjmra-v.vf utfjmrb-h.vf \
		utfjmrb-v.vf utfjmrc-h.vf utfjmrc-v.vf \
		utfjmrd-h.vf utfjmrd-v.vf utfjmre-h.vf \
		utfjmre-v.vf utfjmrf-h.vf utfjmrf-v.vf \
		utfkgr0-h.vf utfkgr0-v.vf utfkgr1-h.vf \
		utfkgr1-v.vf utfkgr2-h.vf utfkgr2-v.vf \
		utfkgr3-h.vf utfkgr3-v.vf utfkgr4-h.vf \
		utfkgr4-v.vf utfkgr5-h.vf utfkgr5-v.vf \
		utfkgr6-h.vf utfkgr6-v.vf utfkgr7-h.vf \
		utfkgr7-v.vf utfkgr8-h.vf utfkgr8-v.vf \
		utfkgr9-h.vf utfkgr9-v.vf utfkgra-h.vf \
		utfkgra-v.vf utfkgrb-h.vf utfkgrb-v.vf \
		utfkgrc-h.vf utfkgrc-v.vf utfkgrd-h.vf \
		utfkgrd-v.vf utfkgre-h.vf utfkgre-v.vf \
		utfkgrf-h.vf utfkgrf-v.vf utfkmr0-h.vf \
		utfkmr0-v.vf utfkmr1-h.vf utfkmr1-v.vf \
		utfkmr2-h.vf utfkmr2-v.vf utfkmr3-h.vf \
		utfkmr3-v.vf utfkmr4-h.vf utfkmr4-v.vf \
		utfkmr5-h.vf utfkmr5-v.vf utfkmr6-h.vf \
		utfkmr6-v.vf utfkmr7-h.vf utfkmr7-v.vf \
		utfkmr8-h.vf utfkmr8-v.vf utfkmr9-h.vf \
		utfkmr9-v.vf utfkmra-h.vf utfkmra-v.vf \
		utfkmrb-h.vf utfkmrb-v.vf utfkmrc-h.vf \
		utfkmrc-v.vf utfkmrd-h.vf utfkmrd-v.vf \
		utfkmre-h.vf utfkmre-v.vf utfkmrf-h.vf \
		utfkmrf-v.vf utfmr0-h.vf utfmr0-v.vf \
		utfmr1-h.vf utfmr1-v.vf utfmr2-h.vf \
		utfmr2-v.vf utfmr3-h.vf utfmr3-v.vf \
		utfmr4-h.vf utfmr4-v.vf utfmr5-h.vf \
		utfmr5-v.vf utfmr6-h.vf utfmr6-v.vf \
		utfmr7-h.vf utfmr7-v.vf utfmr8-h.vf \
		utfmr8-v.vf utfmr9-h.vf utfmr9-v.vf \
		utfmra-h.vf utfmra-v.vf utfmrb-h.vf \
		utfmrb-v.vf utfmrc-h.vf utfmrc-v.vf \
		utfmrd-h.vf utfmrd-v.vf utfmre-h.vf \
		utfmre-v.vf utfmrf-h.vf utfmrf-v.vf \
		utftgr0-h.vf utftgr0-v.vf utftgr1-h.vf \
		utftgr1-v.vf utftgr2-h.vf utftgr2-v.vf \
		utftgr3-h.vf utftgr3-v.vf utftgr4-h.vf \
		utftgr4-v.vf utftgr5-h.vf utftgr5-v.vf \
		utftgr6-h.vf utftgr6-v.vf utftgr7-h.vf \
		utftgr7-v.vf utftgr8-h.vf utftgr8-v.vf \
		utftgr9-h.vf utftgr9-v.vf utftgra-h.vf \
		utftgra-v.vf utftgrb-h.vf utftgrb-v.vf \
		utftgrc-h.vf utftgrc-v.vf utftgrd-h.vf \
		utftgrd-v.vf utftgre-h.vf utftgre-v.vf \
		utftgrf-h.vf utftgrf-v.vf utftmr0-h.vf \
		utftmr0-v.vf utftmr1-h.vf utftmr1-v.vf \
		utftmr2-h.vf utftmr2-v.vf utftmr3-h.vf \
		utftmr3-v.vf utftmr4-h.vf utftmr4-v.vf \
		utftmr5-h.vf utftmr5-v.vf utftmr6-h.vf \
		utftmr6-v.vf utftmr7-h.vf utftmr7-v.vf \
		utftmr8-h.vf utftmr8-v.vf utftmr9-h.vf \
		utftmr9-v.vf utftmra-h.vf utftmra-v.vf \
		utftmrb-h.vf utftmrb-v.vf utftmrc-h.vf \
		utftmrc-v.vf utftmrd-h.vf utftmrd-v.vf \
		utftmre-h.vf utftmre-v.vf utftmrf-h.vf \
		utftmrf-v.vf

DVIPDFMDIR_SRC=	${WRKSRC}/fontmap/dvipdfm
DVIPDFMDIR_DST=	${TEXMFLOCAL}/dvipdfm/otf
DVIPDFMFILES=	cktx.map hiraginox.map kozukax.map morisawax.map
DVIPDFMFILES_O=	"cktx.map(for dvipdfmx)" \
		"hiraginox.map(for dvipdfmx)" \
		"kozukax.map" \
		"morisawax.map(for dvipdfmx)"

DVIPSDIR_SRC=	${WRKSRC}/fontmap/dvips
DVIPSDIR_DST=	${TEXMFLOCAL}/dvips/ptex/otf
DVIPSFILES=	ckt.map hiragino.map kozuka.map morisawa.map
DVIPSFILES_O=	"ckt.map(for udvips)" \
		"hiragino.map(for udvips)"\
		"kozuka.map" \
		"morisawa.map(for udvips)"

DOC_FILES=	readme.txt

do-build:
	cd ${WRKSRC} && ${SH} ./makeotf

post-build:
	${MKDIR} ${DVIPDFMDIR_SRC}
	for F in ${DVIPDFMFILES_O};\
	do \
		${CP}	"${DVIPDFMDIR_SRC}/../$${F}" \
			${DVIPDFMDIR_SRC}/`echo "$${F}" | ${SED} -e 's,(.*$$,,'`;\
	done
	${MKDIR} ${DVIPSDIR_SRC}
	for F in ${DVIPSFILES_O};\
	do \
		${CP}	"${DVIPSDIR_SRC}/../$${F}" \
			${DVIPSDIR_SRC}/`echo "$${F}" | ${SED} -e 's,(.*$$,,'`;\
	done

pre-install:
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${ECHO_CMD} "@comment AUTOMATICALLY GENERATED PLIST" > ${PLIST}
	@${ECHO_CMD} "${DVIPDFMDIR_DST}/cid-otf-noembed.map"  >> ${PLIST}
.for D in CLASS OFM TFM VF DVIPDFM DVIPS
.for F in ${${D}FILES}
	@${ECHO_CMD} "${${D}DIR_DST}/${F}"  >> ${PLIST}
.endfor
	@${ECHO_CMD} "@dirrm ${${D}DIR_DST}"  >> ${PLIST}
.endfor
	@${ECHO_CMD} "%%PORTDOCS%%%%DOCSDIR%%/readme.txt" >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%%%DOCSDIR%%/otfmanual.pdf" >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%%%DOCSDIR%%/vfontmap.platex-otf" >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%@dirrm %%DOCSDIR%%"  >> ${PLIST}
	@${ECHO_CMD} "@exec if [ -x ${MKTEXLSR} ]; then ${MKTEXLSR}; fi"  >> ${PLIST}
	@${ECHO_CMD} "@unexec if [ -x ${MKTEXLSR} ]; then ${MKTEXLSR}; fi"  >> ${PLIST}

do-install:
.for D in CLASS OFM TFM VF DVIPDFM DVIPS
	${MKDIR} ${PREFIX}/${${D}DIR_DST}
	${INSTALL_DATA} ${${D}FILES:S,^,${${D}DIR_SRC}/,} ${PREFIX}/${${D}DIR_DST}
.endfor
	${INSTALL_DATA} ${FILESDIR}/cid-otf-noembed.map ${PREFIX}/${DVIPDFMDIR_DST}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fontmap/vfontmap.txt  \
			${DOCSDIR}/vfontmap.platex-otf
	${INSTALL_DATA} ${DISTDIR}/otfmanual.pdf ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
