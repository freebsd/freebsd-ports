# New ports collection makefile for: shinonome
# Date created:		June 15 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	font-shinonome
PORTVERSION=	0.9.11.p1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://openlab.jp/efont/dist/shinonome/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	${PORTNAME:C/^font-//}-${PORTVERSION:C/.p/p/}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Shinonome Japanese fonts, 12/14/16 dots

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/${PORTNAME:C/^font-//}-${PORTVERSION:C/.p.*$//}
USE_BZIP2=	yes
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR} \
		FONTSALIAS=${DATADIR}/fonts.alias
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

PORTDOCS=	AUTHORS BUGS ChangeLog ChangeLog.0 DESIGN.12 DESIGN.14	\
		DESIGN.16 DESIGN.18 INSTALL README THANKS TODO LICENSE

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

FONTNAMES=\
	shnm6x12a    shnm6x12ab   shnm6x12ai   shnm6x12abi   \
	shnm6x12r    shnm6x12rb   shnm6x12ri   shnm6x12rbi   \
	shnm7x14a    shnm7x14ab   shnm7x14ai   shnm7x14abi   \
	shnm7x14r    shnm7x14rb   shnm7x14ri   shnm7x14rbi   \
	shnm8x16a    shnm8x16ab   shnm8x16ai   shnm8x16abi   \
	shnm8x16r    shnm8x16rb   shnm8x16ri   shnm8x16rbi   \
	shnm9x18a    shnm9x18ab   shnm9x18ai   shnm9x18abi   \
	shnm9x18r    shnm9x18rb   shnm9x18ri   shnm9x18rbi   \
	shnmk12      shnmk12b     shnmk12i     shnmk12bi     \
	shnmk12p     shnmk12pb    shnmk12pi    shnmk12pbi    \
	shnmk12min   shnmk12minb  shnmk12mini  shnmk12minbi  \
	shnmk12maru  shnmk12marub shnmk12marui shnmk12marubi \
	shnmk14      shnmk14b     shnmk14i     shnmk14bi     \
	shnmk14min   shnmk14minb  shnmk14mini  shnmk14minbi  \
	shnmk16      shnmk16b     shnmk16i     shnmk16bi     \
	shnmk16min   shnmk16minb  shnmk16mini  shnmk16minbi

do-build:
	@${ECHO_CMD} -n "Compressing PCF fonts"
	@cd ${WRKSRC} && for F in ${FONTNAMES}; do \
		${LOCALBASE}/bin/bdftopcf bdf/$${F}.bdf | ${GZIP_CMD} > $${F}.pcf.gz; \
		${ECHO_CMD} -n "."; \
	done
	@${ECHO_CMD} "Done"

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FONTNAMES:C/$/.pcf.gz/} fonts.alias ${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/shinonome
	${LN} -s -f ${DATADIR}/*.pcf.gz ${LOCALBASE}/${LOCAL_FONTSDIR}/shinonome/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/misc
	${LN} -s -f ${DATADIR}/*.pcf.gz ${LOCALBASE}/${X_FONTSDIR}/misc/

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
