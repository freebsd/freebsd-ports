# New ports collection makefile for:	k12font
# Date created:		24 June 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kaname12
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		http://www.din.or.jp/~storm/fonts/
DISTNAME=	kaname_k12_bdf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		knm_new_linux.tar.gz
EXTRACT_ONLY=	knm_new_linux.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 12-dot Kanji font

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/fonts

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}
DOCSDIR=	${PREFIX}/share/doc/k12

post-extract:
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme            ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.kaname_bdf ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc.orig/*        ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
