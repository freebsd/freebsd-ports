# Created by: Mita Yoshio <mita@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	kaname12
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	PORTS_JP
DISTNAME=	kaname_k12_bdf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		knm_new_linux.tar.gz
EXTRACT_ONLY=	knm_new_linux.tar.gz

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	X11 12-dot Kanji font

USES=		fonts
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

WRKSRC=		${WRKDIR}/fonts

MAKE_ENV=	FONTSDIR=${FONTSDIR:S,${PREFIX},,g} MKDIR="${MKDIR}"
PLIST_SUB=	FONTSDIR=${FONTSDIR}
DOCSDIR=	${PREFIX}/share/doc/k12

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-extract:
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.alias \
		${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme            ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.kaname_bdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc.orig/*        ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
