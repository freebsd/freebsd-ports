# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	marumoji
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	LOCAL/hrs/${PORTNAME}
PKGNAMEPREFIX=	ja-font-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese marumoji fonts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mkbold:x11-fonts/mkbold-mkitalic \
		bdftopcf:x11-fonts/bdftopcf

USES=		fonts:fc
FONTPATHSPEC=	${FONTNAME}:unscaled:pri=60
NO_ARCH=	yes
MAKE_ENV=	FONTSDIR=${FONTSDIR:S,${PREFIX},,}
SUB_FILES=	Makefile pkg-install
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

${WRKSRC}/maru16.bdf:
	cd ${WRKSRC} && ${SED} -f m18to16.sed < maru18.bdf > maru16.bdf

pre-build: ${WRKSRC}/maru16.bdf apply-slist
	${INSTALL_DATA} ${WRKDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
