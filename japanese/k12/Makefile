# New ports collection makefile for:	k12font
# Version required:	1.0
# Date created:		24 June 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.6 1998/08/07 22:43:07 asami Exp $
#

DISTNAME=	kaname_k12_bdf
PKGNAME=	ja-kaname12-1.0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/FreeBSD/etc/

MAINTAINER=	mita@jp.FreeBSD.org

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/k12
	@${CP} ${WRKSRC}/readme.kaname_bdf ${PREFIX}/share/doc/k12
	@${CP} ${WRKSRC}/doc.orig/*        ${PREFIX}/share/doc/k12
.endif

.include <bsd.port.mk>
