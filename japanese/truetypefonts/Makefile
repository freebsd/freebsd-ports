# New ports collection makefile for:	Japanese TrueType fonts
# Date created:		16 November 1998
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	truetypefonts
PORTVERSION=	1998.10.20
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.linux.or.jp/%7Eishikawa/linux/dists/FreeType/
DISTNAME=	xtt-fonts_0.${PORTVERSION:S/.//g}-3

MAINTAINER=	candy@kgc.co.jp

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/xtt-fonts-0.${PORTVERSION:S/.//g}
NO_BUILD=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

.include <bsd.port.pre.mk>

do-install:
.if !exists(${FONTDIR})
	@${ECHO} "*********************************************************"
	@${ECHO} "Please add ${FONTDIR} to your font path"
	@${ECHO} "in /etc/XF86Config."
	@${ECHO} "*********************************************************"
	${MKDIR} ${FONTDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/wadalab-gothic.ttf ${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/watanabe-mincho.ttf ${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${FONTDIR}/fonts.dir.truetype
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${FONTDIR}/fonts.alias.truetype
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
