# New ports collection makefile for:	pTeX-common
# Version required:	2.1.5
# Date created:		05 Oct 1997
# Whom:			max
#
# $Id: Makefile,v 1.22 1997/10/05 08:32:25 max Exp $
#

DISTNAME=	web2c-7.0
PKGNAME=	ja-ptex-common-2.1.5
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex215/web2c/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} web-7.0.tar.gz texmflib-7.2.tar.gz

MAINTAINER=	max@FreeBSD.ORG

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
USE_GMAKE=	yes
STRIP=		# some shell scripts
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} web-7.0.tar.gz

BINARIES=	bibtex dmp dvicopy dvitomp dvitype gftodvi gftopk gftype \
		inimf inimpost initex kpsewhich mf mft mltex mpost \
		mpto newer patgen pktogf pktype pooltype tangle \
		tex vftovp virmf virmpost virtex vptovf weave

# Using GNU_CONFIGURE doesn't work, for some reason.
do-configure:
	@(cd ${WRKSRC}; \
	  ac_cv_path_install="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    ./configure --prefix=${PREFIX})

pre-install:
.if defined(BATCH)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL BATCH
.else
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL
.endif
	@${EXTRACT_CMD} --exclude 'texmf/tex/latex/base/*' -C ${PREFIX}/share \
	  -zxf ${DISTDIR}/texmflib-7.2.tar.gz
	@${RMDIR} ${PREFIX}/share/texmf/tex/generic/images ${PREFIX}/share/texmf/bibtex/bib/misc
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

post-install:
.for bin in ${BINARIES}
	@strip ${PREFIX}/bin/${bin}
.endfor
	@/bin/ln -fs tex ${PREFIX}/bin/ptex-common

.include <bsd.port.mk>
