# Created by: Hyogeol Lee <hyogeollee@gmail.com>
# $FreeBSD$

PORTNAME=	ko.TeX-fonts-base
PORTVERSION=	0.1.0.20070927
PORTREVISION=	5
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/current/
DISTNAME=	ko.tex-unfonts-base-20070927

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Korean TeX base fonts

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
DOCS=		COPYING LICENSE MANIFEST

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/fonts && ${COPYTREE_SHARE} . ${STAGEDIR}${TEXMF_FONTS})
	(cd ${WRKSRC}/tex && ${COPYTREE_SHARE} . ${STAGEDIR}${TEXMF_TEX})

.include <bsd.port.mk>
