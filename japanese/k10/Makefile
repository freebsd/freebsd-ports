# Created by: Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
# $FreeBSD$

PORTNAME=	naga10
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013391/fonts/
DISTNAME=	knj10-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 10-dot Kanji font 'naga10 font'

BUILD_DEPENDS=	mkbold:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/naga10
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/naga10/

.include <bsd.port.mk>
