# New ports collection makefile for:	kappafont
# Date created:		8 Oct 1998
# Whom: Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	kappa20
PORTVERSION=	0.394
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://kappa.allnet.ne.jp/20dot.fonts/
DISTNAME=	Kappa20-${PORTVERSION}

MAINTAINER=	ginga@athena.club.ne.jp

USE_X_PREFIX=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ARGS=	TARGETDIR="${PREFIX}/${FONTSDIR}"
PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/ja/${PORTNAME}/README.euc-jp
#	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/pcf/fonts.alias.kappa ${PREFIX}/share/doc/${PORTNAME}/
.endif

.include <bsd.port.post.mk>
