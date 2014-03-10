# $FreeBSD$

PORTNAME=	jsclasses
PORTVERSION=	1.0.20110510
CATEGORIES=	japanese print
MASTER_SITES=	http://oku.edu.mie-u.ac.jp/~okumura/jsclasses/:0 \
		http://oku.edu.mie-u.ac.jp/~okumura/texfaq/:1
PKGNAMEPREFIX=	platex-
DISTFILES=	${PORTNAME}-${PORTVERSION:S/^1.0.20//}${EXTRACT_SUFX}:0 \
		jis-tfm${EXTRACT_SUFX}:1 \
		jis-pl${EXTRACT_SUFX}:1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	New document class files for pLaTeX

USES=		zip
USE_TEX=	tetex latex ptex
NO_BUILD=	YES
PLIST_SUB=	CLASSDIR=${CLASSDIR} TFMDIR=${TFMDIR} \
		PLDIR=${PLDIR} MKTEXLSR=${MKTEXLSR} \
		TEXMFDIR=${TEXMFDIR}
WRKSRC=		${WRKDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

CLASSDIR=	${TEXMFDIR}/ptex/platex/js
CLASS_FILES=	jsarticle.cls jsbook.cls \
		jsclasses.dtx jsclasses.ins jspf.cls \
		jsverb.dtx jsverb.ins jsverb.sty \
		kiyou.cls minijs.sty \
		morisawa.dtx morisawa.ins morisawa.sty \
		okumacro.dtx okumacro.ins okumacro.sty \
		okuverb.dtx okuverb.ins okuverb.sty \

TFMDIR=		${TEXMFDIR}/fonts/tfm/jis
TFM_FILES=	jis-v.tfm jis.tfm jisg-v.tfm jisg.tfm \
		jisgn-v.tfm jisgn.tfm jisn-v.tfm jisn.tfm

PLDIR=		${TEXMFDIR}/fonts/source/jis
PL_FILES=	jis-v.pl jis.pl jisn-v.pl jisn.pl

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${CLASS_FILES} ${PREFIX}/${CLASSDIR}
	${MKDIR} ${PREFIX}/${TFMDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${TFM_FILES} ${PREFIX}/${TFMDIR}
	${MKDIR} ${PREFIX}/${PLDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PL_FILES} ${PREFIX}/${PLDIR}

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
