# New ports collection makefile for:	elisa8x8
# Date created:		17 Aug. 1998
# Whom: Toshihiko SHIMOKAWA <toshi@tea.forus.or.jp> & ELISA Font Project
#
# $FreeBSD$
#

PORTNAME=	elisa8x8
PORTVERSION=	1.0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.tea.forus.or.jp/toshi/exhibition/
DISTNAME=	elisat10

MAINTAINER=	toshi@tea.forus.or.jp
COMMENT=	X11 8-dot kanji font 'elisa font'

RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

NO_WRKSUBDIR=	yes

BDFTOPCF_CMD=	${PREFIX}/bin/bdftopcf
MKFONTDIR_CMD=	${PREFIX}/bin/mkfontdir
FONTSDIR=	lib/X11/fonts/local
INSTALLDIR=	${PREFIX}/${FONTSDIR}
DOCDIR=		${PREFIX}/share/doc/elisa
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
	${INSTALL_DATA} ${MYPORTDOCS} ${DOCDIR} ;\
	)
.endif

.include <bsd.port.post.mk>
