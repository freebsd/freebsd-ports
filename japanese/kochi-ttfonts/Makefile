# New ports collection makefile for:	Kochi TrueType fonts
# Date created:		6 January 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	kochi-ttfonts
PORTVERSION=	20030809
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://downloads.sourceforge.jp/efont/5411/ \
		${MASTER_SITE_PORTS_JP}
DISTFILES=	kochi-substitute-${PORTVERSION}.tar.bz2

MAINTAINER=	kanou@khdd.net
COMMENT=	Free Japanese TrueType fonts named 'Kochi'

USE_X_PREFIX=	yes
USE_BZIP2=	yes
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/TrueType
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

WRKSRC=	${WRKDIR}/kochi-substitute-${PORTVERSION}

do-install:
.if !exists(${PREFIX}/${FONTSDIR})
	@${ECHO} "*********************************************************"
	@${ECHO} "Please add ${PREFIX}/${FONTSDIR} to your font path"
	@${ECHO} "and load 'xtt' module in /etc/XF86Config."
	@${ECHO} "*********************************************************"
	${MKDIR} ${PREFIX}/${FONTSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/*.ttf \
			${FILESDIR}/fonts.dir.kochi \
			${FILESDIR}/fonts.alias.kochi \
			${PREFIX}/${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/kochi-ttfonts
	${INSTALL_DATA} ${WRKSRC}/README.ja ${WRKSRC}/COPYING \
		${PREFIX}/share/doc/ja/kochi-ttfonts
	${MKDIR} -p ${PREFIX}/share/doc/ja/kochi-ttfonts/docs/ayu20gothic
	${INSTALL_DATA} ${WRKSRC}/docs/README \
		${PREFIX}/share/doc/ja/kochi-ttfonts/docs
	${INSTALL_DATA} ${WRKSRC}/docs/ayu20gothic/* \
		${PREFIX}/share/doc/ja/kochi-ttfonts/docs/ayu20gothic
	${MKDIR} -p ${PREFIX}/share/doc/ja/kochi-ttfonts/docs/k14goth
	${INSTALL_DATA} ${WRKSRC}/docs/k14goth/* \
		${PREFIX}/share/doc/ja/kochi-ttfonts/docs/k14goth
	${MKDIR} -p ${PREFIX}/share/doc/ja/kochi-ttfonts/docs/kappa20
	${INSTALL_DATA} ${WRKSRC}/docs/kappa20/* \
		${PREFIX}/share/doc/ja/kochi-ttfonts/docs/kappa20
	${MKDIR} -p ${PREFIX}/share/doc/ja/kochi-ttfonts/docs/naga10
	${INSTALL_DATA} ${WRKSRC}/docs/naga10/* \
		${PREFIX}/share/doc/ja/kochi-ttfonts/docs/naga10
	${MKDIR} -p ${PREFIX}/share/doc/ja/kochi-ttfonts/docs/shinonome12
	${INSTALL_DATA} ${WRKSRC}/docs/shinonome12/* \
		${PREFIX}/share/doc/ja/kochi-ttfonts/docs/shinonome12
	${MKDIR} -p ${PREFIX}/share/doc/ja/kochi-ttfonts/docs/shinonome16
	${INSTALL_DATA} ${WRKSRC}/docs/shinonome16/* \
		${PREFIX}/share/doc/ja/kochi-ttfonts/docs/shinonome16
	${MKDIR} -p ${PREFIX}/share/doc/ja/kochi-ttfonts/docs/wadalab
	${INSTALL_DATA} ${WRKSRC}/docs/wadalab/* \
		${PREFIX}/share/doc/ja/kochi-ttfonts/docs/wadalab
.endif
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
