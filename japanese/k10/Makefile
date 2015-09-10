# Created by: Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
# $FreeBSD$

PORTNAME=	naga10
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013391/fonts/
DISTNAME=	knj10-${PORTVERSION}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	X11 10-dot Kanji font 'naga10 font'

BUILD_DEPENDS=	mkbold:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

USES=		fonts

MAKE_ENV=	FONTSDIR=${FONTSDIR:S,${PREFIX},,}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
