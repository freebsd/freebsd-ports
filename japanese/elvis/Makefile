# New ports collection makefile for:    elvis + japanese patch
# Version required:     1.8 pl 4 + j 1.1
# Date created:         5 October 1995
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id$
#

DISTNAME=       elv18src
PKGNAME=        jp-elvis-1.8.4
CATEGORIES+=    japanese
MASTER_SITES=   ftp://ftp.cs.pdx.edu/pub/elvis/
EXTRACT_SUFX=	.tgz

PATCH_SITES=    ftp://ftp.foretune.co.jp/pub/tools/jelvis/
PATCHFILES=     jelvis1.8p4-j1.1.tar.Z
PATCH_DIST_STRIP=       -p1

MAINTAINER=     sanpei@yy.cs.keio.ac.jp

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

NO_WRKSUBDIR=	yes

post-patch:
	cp ${WRKSRC}/Makefile.mix ${WRKSRC}/Makefile

post-install:
	if [ ! -d ${PREFIX}/share/jp-elvis ]; then \
		mkdir -p ${PREFIX}/share/jp-elvis; \
	fi
	cp ${WRKSRC}/README.j18 ${PREFIX}/share/jp-elvis

.include <bsd.port.mk>
