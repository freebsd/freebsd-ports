# New ports collection makefile for:	Kochi TrueType fonts
# Date created:		6 January 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	kochi-ttfonts
PORTVERSION=	20011227
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.on.cs.keio.ac.jp/~yasu/linux/fonts/
DISTFILES=	kochi-mincho-0.1.${PORTVERSION}.tar.bz2 \
		kochi-gothic-0.0.${PORTVERSION}.tar.bz2

MAINTAINER=	kanou@mil.allnet.ne.jp

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

USE_X_PREFIX=	yes
USE_BZIP2=	yes
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/TrueType
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

post-extract:
	(cd ${WRKDIR}/kochi-mincho/examples; \
	 ${MV} fonts.dir.xtt fonts.dir.kochi )

do-install:
.if !exists(${PREFIX}/${FONTSDIR})
	@${ECHO} "*********************************************************"
	@${ECHO} "Please add ${PREFIX}/${FONTSDIR} to your font path"
	@${ECHO} "and load 'xtt' module in /etc/XF86Config."
	@${ECHO} "*********************************************************"
	${MKDIR} ${PREFIX}/${FONTSDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/kochi-gothic/fonts/kochi-gothic.ttf \
			${WRKDIR}/kochi-mincho/fonts/kochi-mincho.ttf \
			${WRKDIR}/kochi-mincho/examples/fonts.dir.kochi \
			${FILESDIR}/fonts.alias.kochi \
			${PREFIX}/${FONTSDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
