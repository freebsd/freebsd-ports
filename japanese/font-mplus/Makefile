# New ports collection makefile for:	M+ Fonts
# Date created:		July 17 2002
# Whom:			The 244th namelessness at 2ch.net
#
# $FreeBSD$
#

PORTNAME=	mplusfonts
PORTVERSION=	2.2.4
PORTREVISION=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://downloads.sourceforge.jp/mplus-fonts/5030/ \
		http://wids.net/archive/mplusfonts/distfiles/
DISTNAME=	mplus_bitmap_fonts-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	12x13 dots X11 kanji fonts with simple and readable design

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDES=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_BUILD=	yes

.include <bsd.port.pre.mk>

DOCS=		INSTALL_E LICENSE_E README_E \
		INSTALL_J LICENSE_J README_J

FONTSDIR=	${PREFIX}/lib/X11/fonts/local
PLIST_SUB=	FONTSDIR=${FONTSDIR:S/${PREFIX}\///}

pre-install:
	@${MKDIR} ${DOCSDIR}
.for i in e j
	@${INSTALL_DATA} ${WRKSRC}/fonts_${i}/fonts.alias \
		${DOCSDIR}/fonts.alias.${i}
	@${CAT} ${DOCSDIR}/fonts.alias.${i} >> ${DOCSDIR}/fonts.alias
.endfor
	@${INSTALL_DATA} ${WRKSRC}/fonts_e/euro/fonts.alias \
		${DOCSDIR}/fonts.alias.euro
	@${CAT} ${DOCSDIR}/fonts.alias.euro >> ${DOCSDIR}/fonts.alias
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
	cd ${WRKSRC} && \
		DESTDIR="${FONTSDIR}" ${WRKSRC}/install_mplus_fonts
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
