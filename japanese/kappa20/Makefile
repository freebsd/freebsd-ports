# New ports collection makefile for:	kappafont
# Date created:		8 Oct 1998
# Whom: Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	kappa20
PORTVERSION=	0.394
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://kappa.allnet.ne.jp/20dot.fonts/
DISTNAME=	Kappa20-${PORTVERSION}

MAINTAINER=	ginga@athena.club.ne.jp

USE_X_PREFIX=	yes
USE_BZIP2=	yes

BUILD_DEPENDS=	mkitalic:${PORTSDIR}/x11-fonts/mkitalic

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ARGS=	FONTSDIR="${FONTSDIR}"
PLIST_SUB=	FONTSDIR=${FONTSDIR}

post-extract:
	(cd ${WRKSRC} ; ${MV} Makefile Makefile.dist)
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/ja/${PORTNAME}/README.euc-jp
#	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
#	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/pcf/fonts.alias.kappa ${PREFIX}/share/doc/${PORTNAME}/
.endif

.include <bsd.port.post.mk>
