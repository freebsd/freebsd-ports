# New ports collection makefile for:	 ja-latex2html
# Date created:		3 Apr 1999
# Whom:			Sugimoto Sadahiro <ixtl@utmc.or.jp>
#
# $FreeBSD$
#

PORTNAME=	latex2html
PORTVERSION=	${VERSION}j${JP_VERSION}
PORTREVISION=	3
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=     support/${PORTNAME}
DISTNAME=       ${PORTNAME}-${VERSION:S,.,-,g}

PATCH_SITES=	http://takeno.iee.niit.ac.jp/~shige/TeX/latex2html/data/
PATCHFILES=	l2h-2002-2-1+jp${JP_VERSION}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ixtl@utmc.or.jp
COMMENT=	Japanese LaTeX2HTML with JA patch

BUILD_DEPENDS=	platex:${PORTSDIR}/japanese/ptex-tetex
RUN_DEPENDS=	dvips:${PORTSDIR}/japanese/dvipsk \
		gs:${PORTSDIR}/japanese/ghostscript-gnu-jpnfont \
		anytopnm:${PORTSDIR}/graphics/netpbm

VERSION=	2002.2.1
JP_VERSION=	2.0

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--shlibdir=${DATADIR} \
		--enable-png \
		--with-perl=${PERL} \
		--with-texpath=${LOCALBASE}/${TEXMFDIR}/ptex/platex/html
PLIST_SUB=	TEXMFDIR=${TEXMFDIR}

TEXMFDIR?=	share/texmf

DOC_FILES=	FAQ INSTALL LICENSE README README.patch-2002jp \
		README.patch-99.1jp

post-install:
	(cd ${WRKSRC}; csh mkwrapper ${PREFIX})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
