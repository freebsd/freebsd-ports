# New ports collection makefile for:	ja-tcsh NLS catalog (Koshiki Yukari)
# Version required:	6.07.09b5
# Date created:		19 August 1998
# Whom:			issei <issei@jp.FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	tcsh-6.07.09
PKGNAME=	ja-tcsh-nls-koshiki-6.07.09b5
CATEGORIES=	japanese shells
MASTER_SITES=	http://www2.wbs.ne.jp/~znc/tcsh/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www2.wbs.ne.jp/~znc/tcsh/
PATCHFILES=	${DISTNAME}.kanji.patch7b5.gz

MAINTAINER=	issei@jp.FreeBSD.ORG

PATCH_DIST_STRIP=	-p1
PLIST=		../tcsh-nls-generic/pkg/PLIST
NLSSRC=		tcsh-6.07.09/nls/ja.koshiki

.include "../tcsh-nls-generic/Makefile"
