# New ports collection makefile for:	elisa8x8
# Version required:	1.0
# Date created:		17 Aug. 1998
# Whom: Toshihiko SHIMOKAWA <toshi@tea.forus.or.jp> & ELISA Font Project
#
# $FreeBSD$
#

DISTNAME=	elisat10
PKGNAME=	ja-elisa8x8-1.0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.tea.forus.or.jp/toshi/exhibition/

MAINTAINER=	toshi@tea.forus.or.jp

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes

BDFTOPCF_CMD=	${PREFIX}/bin/bdftopcf
MKFONTDIR_CMD=	${PREFIX}/bin/mkfontdir
FONTSDIR=	lib/X11/fonts/local
INSTALLDIR=	${PREFIX}/${FONTSDIR}
DOCDIR=		${PREFIX}/share/doc/elisa
PORTDOCS=	elisa100.doc elisat10.doc elisat10.html
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-build:
	@(cd ${WRKDIR}; \
	${BDFTOPCF_CMD} elisat10.bdf   | ${GZIP_CMD} -c > elisat10.pcf.gz ;\
	${BDFTOPCF_CMD} jpnhn4-jis.bdf | ${GZIP_CMD} -c > jpnhn4-jis.pcf.gz ;\
	${BDFTOPCF_CMD} jpnhn4-iso.bdf | ${GZIP_CMD} -c > jpnhn4-iso.pcf.gz ;\
	)

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

do-install:
	@${MKDIR} ${INSTALLDIR} ${DOCDIR}
	@(cd ${WRKSRC} ;\
	${INSTALL_DATA} elisat10.pcf.gz ${INSTALLDIR} ;\
	${INSTALL_DATA} jpnhn4-jis.pcf.gz ${INSTALLDIR} ;\
	${INSTALL_DATA} jpnhn4-iso.pcf.gz ${INSTALLDIR} ;\
	)

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@(cd ${WRKSRC} ;\
	${INSTALL_DATA} ${PORTDOCS} ${DOCDIR} ;\
	)
.endif

.include <bsd.port.mk>
