# New ports collection makefile for:	ja-oleo
# Version required:	1.6
# Date created:		2 March 1997
# Whom:			Yoshiro MIHIRA
#
# $FreeBSD$
#

DISTNAME=	oleo-1.6
PKGNAME=	ja-oleo-1.6
CATEGORIES=	japanese math
MASTER_SITES=	http://www.hh.iij4u.or.jp/~hayasida/oleo/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	oleo
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} oleo-doc.tar.gz

PATCH_SITES=	http://www.hh.iij4u.or.jp/%7Ehayasida/oleo/
PATCHFILES=	oleo-1.6-1.6jb2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=    sanpei@sanpei.org

CONFIGURE_ENV= CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
GNU_CONFIGURE=yes
USE_XLIB=      yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/oleo/ja_JP.EUC
	@${INSTALL_DATA} ${WRKDIR}/USING.eucJP ${PREFIX}/share/doc/oleo/ja_JP.EUC/
.endif

.include <bsd.port.mk>
