# New ports collection makefile for:	Japanese TrueType fonts
# Date created:		16 November 1998
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	truetypefonts
PORTVERSION=	2001.08.18.5
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/t/ttf-xtt
DISTNAME=	ttf-xtt_0.${PORTVERSION:R:S/.//g}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese TrueType Fonts

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/ttf-xtt-0.${PORTVERSION:R:S/.//g}
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/TrueType
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-install:
.if !exists(${PREFIX}/${FONTSDIR})
	@${ECHO_MSG} "*********************************************************"
	@${ECHO_MSG} "Please add ${PREFIX}/${FONTSDIR} to your font path"
	@${ECHO_MSG} "in /etc/XF86Config."
	@${ECHO_MSG} "*********************************************************"
	${MKDIR} ${PREFIX}/${FONTSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/wadalab-gothic.ttf ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/watanabe-mincho.ttf ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir.truetype ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.alias.truetype ${PREFIX}/${FONTSDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
