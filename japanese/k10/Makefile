# New ports collection makefile for:	naga10
# Version required:	1.1
# Date created:		25 Feb 1998
# Whom:	Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $FreeBSD$
#

DISTNAME=	knj10-1.1
PKGNAME=	ja-naga10-1.1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013391/fonts/

MAINTAINER=	usagi@clave.gr.jp

USE_X_PREFIX=	yes

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/naga10
	@${CP} ${WRKSRC}/README ${PREFIX}/share/doc/naga10/
.endif

.include <bsd.port.mk>
