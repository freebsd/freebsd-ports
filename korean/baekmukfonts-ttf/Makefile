# New ports collection makefile for:	Baekmuk Korean TrueType fonts
# Date created:		17 Jan 2000
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	baekmukfonts
PORTVERSION=	2.0
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.mizi.com/pub/baekmuk/obsoletes/
PKGNAMESUFFIX=	-ttf
DISTNAME=	baekmuk${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Baekmuk family Korean TrueType Fonts

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
FONTLIST=	batang gulim dotum hline

.include <bsd.port.pre.mk>

do-install:
.if !exists(${FONTDIR})
	@${ECHO} "*********************************************************"
	@${ECHO} "If you want to use these fonts from X, install"
	@${ECHO} "one of X-TT servers(x11-servers/Xtt*) and add ${FONTDIR}"
	@${ECHO} "to your font path in /etc/XF86Config."
	@${ECHO} "If you want to use these fonts from ghostscript,"
	@${ECHO} "install korean/ftghostscript5 and edit"
	@${ECHO} "${LOCALBASE}/share/ghostscript/5.10ft/hangul/hconfig.ps"
	@${ECHO} "See examples in ${FONTDIR}"
	@${ECHO} "*********************************************************"
	${MKDIR} ${FONTDIR}
.endif
.for FONTNAME in ${FONTLIST}
	${INSTALL_DATA} ${WRKSRC}/${FONTNAME}.ttf ${FONTDIR}
.endfor
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${FONTDIR}/fonts.dir.baekmuk
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${FONTDIR}/fonts.alias.baekmuk
	${INSTALL_DATA} ${FILESDIR}/hconfig.ps ${FONTDIR}/hconfig.ps.baekmuk
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
