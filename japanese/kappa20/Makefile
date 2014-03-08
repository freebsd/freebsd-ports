# Created by: Kawaguti Ginga <ginga@athena.club.ne.jp>
# $FreeBSD$

PORTNAME=	k20fonts
PORTVERSION=	0.396
PORTREVISION=	6
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_NETBSD:S/$/:kappa20/:S/%SUBDIR%/LOCAL_PORTS/} \
		SFJP/x-tt/8412/:ayu20
DISTNAME=	Kappa20-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kappa20 \
		${AYUDISTNAME}${AYU_SUFFIX}:ayu20
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ginga-freebsd@ginganet.org
COMMENT=	X11 20-dot Kanji font 'Kappa20dot + ayu font'

USE_BZIP2=	yes
AYUDISTNAME=	ayu20gothic-1.6
AYU_SUFFIX=	.tar.gz

BUILD_DEPENDS=	mkitalic:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

FONTSDIR=	lib/X11/fonts/local
MAKE_ARGS=	FONTSDIR="${FONTSDIR}"
PLIST_SUB=	FONTSDIR=${FONTSDIR}
DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-extract:
	(cd ${WRKSRC} ; ${TAR} xpzf ${DISTDIR}/${AYUDISTNAME}${AYU_SUFFIX})
	(cd ${WRKSRC} ; ${MV} Makefile Makefile.dist)
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/fonts.alias.ayu ${WRKSRC}/

pre-build:
	(cd ${WRKSRC} ; ${SH} makebdf.sh)

pre-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README.euc-jp

.include <bsd.port.mk>
