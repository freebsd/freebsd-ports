# New ports collection makefile for:    hex103
# Version required:     1.03
# Date created:         Nov 5, 1996
# Whom:                 IMAMURA Tomoaki (tomoak-i@is.aist-nara.ac.jp)
#
# $Id$
#

DISTNAME=	hex103
PKGNAME=	jp-hex-1.03
CATEGORIES=	japanese
MASTER_SITES=	http://www.is.s.u-tokyo.ac.jp/~nayuta/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tomoak-i@is.aist-nara.ac.jp

NO_INSTALL_MANPAGES=	yes
USE_IMAKE=	yes

PREFIX?=	${LOCALBASE}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/jp-hex
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jp-hex
.endif

.include <bsd.port.mk>
