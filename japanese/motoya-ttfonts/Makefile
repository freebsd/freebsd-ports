# New ports collection makefile for:	Motoya TrueType fonts
# Date created:				2004-01-16
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	motoya-ttfonts
PORTVERSION=	0.20040116
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	#
#		You must accept following MOTOYA freefont LICENSE[1], and regist
#		free member for download.  You can get a Japanese mail which
#		contains download URL.
#		http://www.motoyafont.jp/use_consent.htm [1]
#		http://www.motoyafont.jp/toroku.html [2]
DISTFILES=	nfa1.exe nfc1.exe
DIST_SUBDIR=	motoya

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Free Japanese TrueType fonts named 'MOTOYA'

BUILD_DEPENDS+=	lha:${PORTSDIR}/archivers/lha

RESTRICTED=	Personal, non-profit, and evaluation purpose only
NO_CDROM=	Redistribution not permitted in any form
NO_PACKAGE=	Redistribution not permitted in any form

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTSDIR=	lib/X11/fonts/TrueType
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-fetch:
	@[ -f ${DISTDIR}/${DIST_SUBDIR}/nfa1.exe \
			-a -f ${DISTDIR}/${DIST_SUBDIR}/nfc1.exe ] || (	\
	${ECHO} "****************************************************";	\
	${ECHO} "Please get nfa1.exe and nfc1.exe from";		\
	${ECHO} "       http://www.motoyafont.jp/toroku.html";		\
	${ECHO} "And, you must accept following MOTOYA freefont LICENSE."; \
	${ECHO} "	http://www.motoyafont.jp/use_consent.htm";	\
	${ECHO} "Then, put in ${DISTDIR}/${DIST_SUBDIR}/nf{a|c}1.exe.";	\
	${ECHO} "****************************************************";	\
	${FALSE}							\
	)

do-extract:
.for file in ${DISTFILES}
	@lha xiw=${WRKSRC} ${DISTDIR}/${DIST_SUBDIR}/${file} '*/*.ttc'
.endfor

do-install:
.if !exists(${PREFIX}/${FONTSDIR})
	@${ECHO} "***************************************************"
	@${ECHO} "Please add ${PREFIX}/${FONTSDIR} to your font path"
	@${ECHO} "and load 'xtt' module in /etc/XF86Config."
	@${ECHO} "***************************************************"
	${MKDIR} ${PREFIX}/${FONTSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/*.ttc \
			${FILESDIR}/fonts.dir.motoya \
			${FILESDIR}/fonts.alias.motoya \
			${PREFIX}/${FONTSDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
