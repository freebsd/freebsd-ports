# New ports collection makefile for:	platex-jsclasses
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	platex-jsclasses
PORTVERSION=	1.0.20040927
CATEGORIES=	japanese print
MASTER_SITES=	http://oku.edu.mie-u.ac.jp/~okumura/jsclasses/:0 \
		http://oku.edu.mie-u.ac.jp/~okumura/texfaq/:1
PKGNAMEPREFIX=	ja-
DISTFILES=	${PORTNAME:S/^platex-//}-${PORTVERSION:S/^1.0.20//}${EXTRACT_SUFX}:0 \
		jis-tfm${EXTRACT_SUFX}:1 \
		jis-pl${EXTRACT_SUFX}:1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	New document class files for pLaTeX

RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		ptex:${PORTSDIR}/japanese/ptex-tetex \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

USE_ZIP=	YES
NO_BUILD=	YES
PLIST_SUB=	CLASSDIR=${CLASSDIR} TFMDIR=${TFMDIR} \
		PLDIR=${PLDIR} MKTEXLSR=${MKTEXLSR}
WRKSRC=		${WRKDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

CLASSDIR=	${TEXMFLOCAL}/ptex/platex/js
CLASS_FILES=	jsarticle.cls jsbook.cls \
		jsclasses.dtx jsclasses.ins jspf.cls \
		morisawa.dtx morisawa.ins morisawa.sty \
		okumacro.dtx okumacro.ins okumacro.sty \
		okuverb.dtx okuverb.ins okuverb.sty \

TFMDIR=		${TEXMFLOCAL}/fonts/tfm/jis
TFM_FILES=	jis-v.tfm jis.tfm jisg-v.tfm jisg.tfm \
		jisgn-v.tfm jisgn.tfm jisn-v.tfm jisn.tfm

PLDIR=		${TEXMFLOCAL}/fonts/source/jis
PL_FILES=	jis-v.pl jis.pl jisn-v.pl jisn.pl

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
	${MKDIR} ${PREFIX}/${TFMDIR}
	${INSTALL_DATA} ${TFM_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${TFMDIR}
	${MKDIR} ${PREFIX}/${PLDIR}
	${INSTALL_DATA} ${PL_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${PLDIR}

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
