# New ports collection makefile for:	cwTeX Chinese TrueType fonts
# Date created:		18 Dec 2002
# Whom:			Shen Chuan-Hsing <satue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	cwtexttf
PORTVERSION=	1.2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://ftp1.sinica.edu.tw/pub2/tex/cwTeX/cwTeX-TTF/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/cwTeX-TTF/
DISTNAME=	cwtex-ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Five Chinese Big5 TrueType fonts made by cwTeX

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

USE_ZIP=	YES
NO_BUILD=	yes
SHAREMODE=	644
WRKSRC=		${WRKDIR}/texmf/fonts/truetype/cwTeX
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} \
		WANT_GS=${WANT_GS} WITHOUT_X=${WITHOUT_X}

.include <bsd.port.pre.mk>

pre-fetch:
.if defined(WANT_GS)
	@${ECHO} "Ghostscript support will be added."
.endif
.if defined(WITHOUT_X)
	@${ECHO} "X Window support will NOT be added."
.endif
.if !defined(WANT_GS) && !defined(WITHOUT_X)
	@${ECHO} --
	@${ECHO} "Type \"make WANT_GS=yes\" if you want Ghostscript support."
	@${ECHO} "Type \"make WITHOUT_X=yes\" if you DONT want X Window support."
	@${ECHO} "You can use them in combinations."
	@${ECHO} --
.endif

do-install:
.if !exists(${FONTDIR})
	@${MKDIR} ${FONTDIR}
.endif
.for i in bbttf.ttf fttf.ttf kttf.ttf mttf.ttf rttf.ttf
	@${INSTALL_DATA} ${WRKSRC}/${i} ${FONTDIR}
.endfor
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
