# New ports collection makefile for:	k12font
# Date created:		24 June 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kaname12
PORTVERSION=	1.1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		http://www.din.or.jp/~storm/fonts/
DISTNAME=	kaname_k12_bdf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		knm_new_linux.tar.gz

MAINTAINER=	mita@jp.FreeBSD.org
COMMENT=	X11 12-dot kanji font

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/fonts
EXTRACT_ONLY=	knm_new_linux.tar.gz

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

post-extract:
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/k12
	@${INSTALL_DATA} ${WRKSRC}/readme            ${PREFIX}/share/doc/k12
	@${INSTALL_DATA} ${WRKSRC}/readme.kaname_bdf ${PREFIX}/share/doc/k12
	@${INSTALL_DATA} ${WRKSRC}/doc.orig/*        ${PREFIX}/share/doc/k12
.endif

.include <bsd.port.post.mk>
