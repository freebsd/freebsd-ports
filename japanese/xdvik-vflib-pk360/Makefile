# New ports collection makefile for:   xdvik + jp-patch
# Version required:    20c
# Date created:        15 Jun 1998
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $Id: Makefile,v 1.4 1998/10/07 06:11:42 asami Exp $
#

DISTNAME=	xdvik-20c
PKGNAME=	ja-vfxdvik-20c
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-20c/ \
		${MASTER_SITE_LOCAL}

PATCH_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-20c/ \
		${MASTER_SITE_LOCAL}
PATCHFILES=	xdvik20c-j1.0p0d.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	inagaki@tg.rim.or.jp

RUN_DEPENDS=	mf:${PORTSDIR}/japanese/ptex-common
LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_GMAKE=YES
GNU_CONFIGURE=YES
CONFIGURE_ARGS=--enable-shared=yes --with-dvifilter=dvips
#CONFIGURE_ARGS=--enable-shared=yes --with-dvifilter=dvi2ps
CONFIGURE_ENV=ac_cv_path_install="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}"
MAKE_FLAGS=VFLIB='-L$(LOCALBASE)/lib -lVFlib2 -lttf'
STRIP=
MAN1=xdvi.1

TEXMF=		${PREFIX}/share/texmf
XDVIDIR=	${TEXMF}/xdvi
BINARIES=	xdvi

DOCS=		xdvi.FAQ \
		xdvi.icon \
		README \
		README.xdvik20a-j1.1.patch \
		README.xdvik20c-j1.0p0.patch \
		ChangeLog \
		ChangeLog.xdvik20a-j1.1 \
		ChangeLog.xdvik20c-j1.0 \
		READMEs/HEADERS.DOC \
		READMEs/InternalVars \
		READMEs/README.jp-patch \
		READMEs/README.tasai-ussy \
		READMEs/README.markpage+toc+printdvi \
		READMEs/README.markpage+toc+printdvi+paper \
		READMEs/README.xdvik18f-j1.0.patch \
		READMEs/README.xdvik18f-j1.1p5.patch

pre-build:
	@(cd ${WRKSRC} ; find . -name '*.orig' -exec ${RM} -f {} \;)

do-install:
	@(cd ${WRKSRC}/xdvik ; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

post-install:
	@for i in ${BINARIES} ; do \
	    strip ${PREFIX}/bin/$$i ; \
	done
	@$(INSTALL_DATA) $(FILESDIR)/vfontmap $(XDVIDIR)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xdvi
	@for i in ${DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/xdvik/$$i ${PREFIX}/share/doc/xdvi ; \
	done
.endif

.include <bsd.port.mk>
