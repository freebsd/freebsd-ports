# Created by: Mita Yoshio <mita@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	kaname12
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	LOCAL/hrs
PKGNAMEPREFIX=	ja-font-
DISTNAME=	kaname_k12_bdf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		knm_new_linux${EXTRACT_SUFX}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	12-dot Kanji font

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	Makefile pkg-message
MAKEFILE=	${WRKDIR}/Makefile
PORTDOCS=	readme readme.kaname_bdf kaname.doc \
		readme.knm gijutsu-siryou.doc

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install:
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-doc

.include <bsd.port.mk>
