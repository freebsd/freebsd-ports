# New ports collection makefile for:   xdvik+jp-patch(use VFlib)
# Version required:    20
# Date created:        26 Feb 1998
# Whom:                Kentaro Inagaki <JBD01226@niftyserve.or.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/06/14 07:58:50 kuriyama Exp $
#

DISTNAME=	xdvik-20a
PKGNAME=	ja-vfxdvik-20a
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-20/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xdvik20a-j1.1p15.patch.gz

MAINTAINER=	JBD01226@niftyserve.or.jp

RUN_DEPENDS=    mf:${PORTSDIR}/japanese/ptex-common
LIB_DEPENDS=    VFlib\\.2\\.:${PORTSDIR}/japanese/vflib

EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=YES
CONFIGURE_ARGS=--with-dvifilter=dvi2ps
#CONFIGURE_ARGS=--enable-shared=yes --with-dvifilter=dvi2ps
USE_GMAKE=YES

MAN1=xdvi.1 gsftopk.1

pre-patch:
	(cd ${WRKSRC}/xdvik ; \
	${GZCAT} ${DISTDIR}/xdvik20a-j1.1p15.patch.gz | ${PATCH} -s )

pre-build:
	(cd ${WRKSRC} ; find . -name '*.orig' -exec ${RM} -f {} \;)

do-install:
	(cd ${WRKSRC}/xdvik ; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

post-install:
	$(INSTALL_DATA) $(FILESDIR)/vfontmap $(PREFIX)/share/texmf/xdvi
	${MKDIR} ${PREFIX}/share/doc/xdvi
	$(INSTALL_DATA) ${WRKSRC}/xdvik/README* ${PREFIX}/share/doc/xdvi
	$(INSTALL_DATA) ${WRKSRC}/xdvik/ChangeLog* ${PREFIX}/share/doc/xdvi

.include <bsd.port.mk>
