# New ports collection makefile for:	jp-oleo
# Version required:	1.6
# Date created:		2 March 1997
# Whom:			Yoshiro MIHIRA
#
# $Id: Makefile,v 1.1 1997/07/20 17:32:30 max Exp $
#

DISTNAME=	oleo-1.6
PKGNAME=	jp-oleo-1.6
CATEGORIES=	japanese math
MASTER_SITES=	http://www.hh.iij4u.or.jp/~hayasida/oleo/ \
		${MASTER_SITE_GNU}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} oleo-doc.tar.gz

PATCH_SITES=	http://www.hh.iij4u.or.jp/%7Ehayasida/oleo/
PATCHFILES=	oleo-1.6-1.6jb2.diff.gz

MAINTAINER=	sanpei@yy.cs.keio.ac.jp

PATCH_DIST_STRIP=	-p1
GNU_CONFIGURE=yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/oleo/ja_JP.EUC
	@${INSTALL_DATA} ${WRKDIR}/USING.eucJP ${PREFIX}/share/doc/oleo/ja_JP.EUC/
.endif

.include <bsd.port.mk>
