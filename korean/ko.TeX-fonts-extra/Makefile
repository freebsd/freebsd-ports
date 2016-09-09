# Created by: Hyogeol Lee <hyogeollee@gmail.com>
# $FreeBSD$

PORTNAME=	ko.TeX-fonts-extra
PORTVERSION=	0.1.0
PORTREVISION=	5
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/extrafonts/
DISTFILES=	ko.tex-extra-hlfont.tar.gz ko.tex-unfonts-extra.tar.gz

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Korean TeX extra fonts

USE_TEX=	dvipsk latex
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

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/fonts && ${COPYTREE_SHARE} . ${STAGEDIR}${TEXMF_FONTS})
	(cd ${WRKSRC}/tex && ${COPYTREE_SHARE} . ${STAGEDIR}${TEXMF_TEX})

.include <bsd.port.mk>
