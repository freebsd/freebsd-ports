# New ports collection makefile for:	elisa8x8
# Version required:	1.0
# Date created:		17 Aug. 1998
# Whom: Toshihiko SHIMOKAWA <toshi@tea.forus.or.jp> & ELISA Font Project
#
# $Id$
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
FONTSDIR=	${PREFIX}/lib/X11/fonts/misc
DOCDIR=		${PREFIX}/share/doc/elisa
PORTDOCS=	elisa100.doc elisat10.doc elisat10.html

do-build:
	@(cd ${WRKDIR}; \
	${BDFTOPCF_CMD} elisat10.bdf | ${GZIP_CMD} -9 > elisat10.pcf.gz ;\
	${BDFTOPCF_CMD} jpnhn4-jis.bdf | ${GZIP_CMD} -9 > jpnhn4-jis.pcf.gz ;\
	${BDFTOPCF_CMD} jpnhn4-iso.bdf | ${GZIP_CMD} -9 > jpnhn4-iso.pcf.gz ;\
	)

do-install:
	@${MKDIR} ${FONTSDIR} ${DOCDIR}
	@(cd ${WRKSRC} ;\
	${INSTALL_DATA} elisat10.pcf.gz ${FONTSDIR} ;\
	${INSTALL_DATA} jpnhn4-jis.pcf.gz ${FONTSDIR} ;\
	${INSTALL_DATA} jpnhn4-iso.pcf.gz ${FONTSDIR} ;\
	${INSTALL_DATA} ${PORTDOCS} ${DOCDIR} ;\
	${ECHO} "Updating fonts.dir" ;\
	${MKFONTDIR_CMD} ${FONTSDIR} ;\
	${ECHO} "Updating fonts.alias" ;\
	${TOUCH} ${FONTSDIR}/fonts.alias ;\
	${CAT} ${FONTSDIR}/fonts.alias fonts.alias > fonts.alias.tmp ;\
	${INSTALL_DATA} fonts.alias.tmp ${FONTSDIR} ;\
	${MV} -f ${FONTSDIR}/fonts.alias.tmp ${FONTSDIR}/fonts.alias ;\
	)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@(cd ${WRKSRC} ;\
	${INSTALL_DATA} ${PORTDOCS} ${DOCDIR} ;\
	)
.endif
	@${ECHO} "**********************************************************"
	@${ECHO} "You should restart X server or do 'xset fp rehash' command"
	@${ECHO} "to use installed fonts."
	@${ECHO} "**********************************************************"

.include <bsd.port.mk>
