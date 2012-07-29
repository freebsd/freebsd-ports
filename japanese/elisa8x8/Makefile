# New ports collection makefile for:	elisa8x8
# Date created:		17 Aug. 1998
# Whom: Toshihiko SHIMOKAWA <toshi@tea.forus.or.jp> & ELISA Font Project
#
# $FreeBSD$
#

PORTNAME=	elisa8x8
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.bsdbbq.org/~toshi/distfiles/
DISTNAME=	elisat10

MAINTAINER=	toshi@tea.forus.or.jp
COMMENT=	X11 8-dot Kanji font 'elisa font'

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

.include <bsd.port.pre.mk>

NO_WRKSUBDIR=	yes

BDFTOPCF_CMD=	${PREFIX}/bin/bdftopcf
MKFONTDIR_CMD=	${PREFIX}/bin/mkfontdir
FONTSDIR=	lib/X11/fonts/local
INSTALLDIR=	${PREFIX}/${FONTSDIR}
MYPORTDOCS=	elisa100.doc elisat10.doc elisat10.html
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-build:
	@(cd ${WRKDIR}; \
	${BDFTOPCF_CMD} elisat10.bdf   | ${GZIP_CMD} -c > elisat10.pcf.gz ;\
	${BDFTOPCF_CMD} jpnhn4-jis.bdf | ${GZIP_CMD} -c > jpnhn4-jis.pcf.gz ;\
	${BDFTOPCF_CMD} jpnhn4-iso.bdf | ${GZIP_CMD} -c > jpnhn4-iso.pcf.gz ;\
	)

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
	@${MKDIR} ${INSTALLDIR}
	@(cd ${WRKSRC} ;\
	${INSTALL_DATA} elisat10.pcf.gz ${INSTALLDIR} ;\
	${INSTALL_DATA} jpnhn4-jis.pcf.gz ${INSTALLDIR} ;\
	${INSTALL_DATA} jpnhn4-iso.pcf.gz ${INSTALLDIR} ;\
	)

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${MYPORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
