# Created by: Kawaguti Ginga <ginga@athena.club.ne.jp>
# $FreeBSD$

PORTNAME=	kappa20
PORTVERSION=	0.396
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	LOCAL/hrs
PKGNAMEPREFIX=	ja-font-
DISTNAME=	Kappa20-${PORTVERSION}

MAINTAINER=	ginga-freebsd@ginganet.org
COMMENT=	20-dot Kanji font Kappa20

BUILD_DEPENDS=	mkitalic:x11-fonts/mkbold-mkitalic \
		bdftopcf:x11-fonts/bdftopcf

USES=		fonts tar:bzip2
FONTNAME=	misc
NO_ARCH=	yes
MAKE_ARGS=	FONTSDIR="${FONTSDIR:S,${PREFIX},,}"
MAKEFILE=	${WRKDIR}/Makefile
SUB_FILES=	Makefile pkg-install
SUB_LIST=	FONTSALIAS="${DATADIR}/fonts.alias"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist
	cd ${WRKSRC} && ${SH} makebdf.sh

post-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && \
	    ${LN} -s ../../../${DATADIR_REL}/*.pcf.gz .

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
