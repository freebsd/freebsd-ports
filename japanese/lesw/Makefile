# New ports collection makefile for:	lesw
# Version required:	332
# Date created:		11 November 1998
# Whom:			Toshihiko Kodama <kodama@ayame.mfd.cs.fujitsu.co.jp>
#
# $FreeBSD$
#

DISTNAME=	less-332
PKGNAME=	ja-lesw-332
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.big.or.jp/pub/usr2/jam/less/contrib/

PATCH_SITES=	ftp://ftp.big.or.jp/pub/usr2/jam/less/ \
		http://www.st.rim.or.jp/~sasami/lesw/
PATCHFILES=	less-332-iso242.patch.gz \
		less-332-iso242-243.patch.gz \
		less-332-iso243-244.patch.gz \
		less-332-iso244-245.patch.gz \
		less-332-iso245-247.patch.gz \
		less-332-iso247-248.patch.gz \
		lw332i248p10c.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kodama@ayame.mfd.cs.fujitsu.co.jp

GNU_CONFIGURE=	yes

MAN1=		lesw.1 leswkey.1

.include <bsd.port.mk>
