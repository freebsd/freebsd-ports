# New ports collection makefile for:	pTeX-common
# Date created:		05 Oct 1997
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	ptex
PORTVERSION=	2.1.8
PKGNAMESUFFIX=	-common
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex218/web2c/
DISTNAME=	web2c-7.2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		web-7.2.tar.gz \
		texmflib-7.3.tar.gz

MAINTAINER=	max@FreeBSD.org

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
INSTALLS_SHLIBS=	yes
USE_GMAKE=	yes
EXTRACT_ONLY=	${DISTFILES:Ntexmflib-*}
DIST_SUBDIR=	${PORTNAME}
STRIP=		# some shell scripts
MAN1=		access.1 amstex.1 bibtex.1 dmp.1 dvicopy.1 dvitype.1	\
		eplain.1 etex.1 gftodvi.1 gftopk.1 gftype.1 kpsestat.1	\
		kpsewhich.1 latex.1 makempx.1 mf.1 mft.1 mktexlsr.1	\
		mktexmf.1 mktexpk.1 mktextfm.1 mpost.1 mpto.1 newer.1	\
		omega.1 patgen.1 pdftex.1 pktogf.1 pktype.1 pltotf.1	\
		pooltype.1 readlink.1 tangle.1 tex.1 tftopl.1 tie.1	\
		vftovp.1 vptovf.1 weave.1

BINARIES=	bibtex dmp dvicopy dvitomp dvitype gftodvi gftopk gftype \
		inimf inimpost initex kpsewhich mf mft mpost \
		mpto newer patgen pktogf pktype pooltype tangle \
		tex vftovp virmf virmpost virtex vptovf weave

# Using GNU_CONFIGURE doesn't work, for some reason.
do-configure:
	@(cd ${WRKSRC}; \
	  ac_cv_path_install="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    ./configure --prefix=${PREFIX} --enable-shared)

pre-install:
.if defined(BATCH)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL BATCH
.else
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL
.endif
	@${TAR} --exclude 'texmf/tex/latex/base/*' --exclude 'texmf/dvips/*' \
	  -C ${PREFIX}/share -zxf ${DISTDIR}/${DIST_SUBDIR}/texmflib-7.3.tar.gz
	#@${RMDIR} ${PREFIX}/share/texmf/tex/generic/images ${PREFIX}/share/texmf/bibtex/bib/misc

post-install:
.for bin in ${BINARIES}
	@strip ${PREFIX}/bin/${bin}
.endfor
	@${LN} -fs tex ${PREFIX}/bin/ptex-common

.include <bsd.port.mk>
