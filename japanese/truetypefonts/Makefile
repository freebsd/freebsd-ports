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

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

WRKSRC=		${WRKDIR}/xtt-fonts-0.${PORTVERSION:S/.//g}
NO_BUILD=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

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
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
