# New ports collection makefile for:	Japanese TrueType fonts
# Date created:		16 November 1998
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	truetypefonts
PORTVERSION=	2001.03.06
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	ftp://ftp.debian.org/debian/pool/main/t/ttf-xtt/
DISTNAME=	ttf-xtt_0.${PORTVERSION:S/.//g}-9

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

WRKSRC=		${WRKDIR}/ttf-xtt-0.${PORTVERSION:S/.//g}
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
	${INSTALL_DATA} ${FILESDIR}/fonts.dir.truetype ${FONTDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.alias.truetype ${FONTDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
