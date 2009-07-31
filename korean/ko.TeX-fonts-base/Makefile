# New ports collection makefile for:	ko.TeX-fonts-base
# Date created: 			7 January 2008
# Whom:					Hyogeol Lee <hyogeollee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ko.TeX-fonts-base
PORTVERSION=	0.1.0.20070927
PORTREVISION=	2
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/current/
DISTNAME=	ko.tex-unfonts-base-20070927

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Korean TeX base fonts

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
DOCS=		COPYING LICENSE MANIFEST

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	(cd ${WRKDIR}/fonts/ && ${COPYTREE_SHARE} \* ${TEXMF_FONTS})
	(cd ${WRKDIR}/tex/ && ${COPYTREE_SHARE} \* ${TEXMF_TEX})

post-install:
	${MKTEXLSR}
	${UPDMAP_SYS} --enable Map=kotex-base.map

.include <bsd.port.mk>
