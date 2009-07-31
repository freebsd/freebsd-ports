# New ports collection makefile for:	ko.TeX-fonts-extra
# Date created: 			7 January 2008
# Whom:					Hyogeol Lee <hyogeollee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ko.TeX-fonts-extra
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/extrafonts/
DISTFILES=	ko.tex-extra-hlfont.tar.gz ko.tex-unfonts-extra.tar.gz

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Korean TeX extra fonts

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX

CONFLICTS=	hlatex-[0-9]*

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TEXMF=		${PREFIX}/share/texmf-local
TEXMF_FONTS=	${TEXMF}/fonts
TEXMF_TEX=	${TEXMF}/tex

MKTEXLSR=	${PREFIX}/bin/mktexlsr
UPDMAP_SYS=	${PREFIX}/bin/updmap-sys

PLIST_SUB+=	MKTEXLSR=${MKTEXLSR} \
		UPDMAP_SYS=${UPDMAP_SYS}

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKDIR}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
	(cd ${WRKDIR}/fonts/ && ${COPYTREE_SHARE} \* ${TEXMF_FONTS})
	(cd ${WRKDIR}/tex/ && ${COPYTREE_SHARE} \* ${TEXMF_TEX})

post-install:
	${MKTEXLSR}
	${UPDMAP_SYS} --enable Map=kotex-extra-hlfont.map
	${UPDMAP_SYS} --enable Map=kotex-extra.map

.include <bsd.port.mk>
