# New ports collection makefile for:    epson-ttfonts
# Date created:                         20 Feb 2005
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	epson-ttfonts
PORTVERSION=	3.0.20050220
CATEGORIES=     japanese x11-fonts
MASTER_SITES=   http://www2.i-love-epson.co.jp/download/printer/driver/win/page/
DISTNAME=	${EPSONFONTS}
EXTRACT_SUFX=.exe
DIST_SUBDIR=	epson

MAINTAINER=     maho@FreeBSD.org
COMMENT=        EPSON TrueTypeFontVer.3.0, only usable with EPSON printer

RESTRICTED=	"Redistribution not permitted; only usable with EPSON printer."
NO_CDROM=       Redistribution not permitted in any form
NO_PACKAGE=     Redistribution not permitted in any form

EPSONFONTS=	ttf30
USE_X_PREFIX=	yes
USE_ZIP=        yes
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/TrueType
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} ; \
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${EPSONFONTS}.exe | ${TAIL} -c 16591797 >FILE ;\
	${UNZIP_CMD} FILE ; ${RM} FILE

do-install:

.if !exists(${PREFIX}/${FONTSDIR})
	@${ECHO} "*********************************************************"
	@${ECHO} "Please add ${PREFIX}/${FONTSDIR} to your font path"
	@${ECHO} "and load 'freetype' module in /etc/x11/xorg.conf."
	@${ECHO} "*********************************************************"
	${MKDIR} ${PREFIX}/${FONTSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/*.ttf \
			${FILESDIR}/fonts.alias.epson \
			${FILESDIR}/fonts.dir.epson \
			${PREFIX}/${FONTSDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.include <bsd.port.mk>
