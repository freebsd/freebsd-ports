# New ports collection makefile for:	lesw
# Date created:		11 November 1998
# Whom:			Toshihiko Kodama <kodama@ayame.mfd.cs.fujitsu.co.jp>
#
# $FreeBSD$
#

PORTNAME=	lesw
PORTVERSION=	332
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.big.or.jp/pub/usr2/jam/less/contrib/
DISTNAME=	less-${PORTVERSION}

PATCH_SITES=	ftp://ftp.big.or.jp/pub/usr2/jam/less/ \
		http://www.st.rim.or.jp/~sasami/lesw/
PATCHFILES=	${DISTNAME}-iso242.patch.gz \
		${DISTNAME}-iso242-243.patch.gz \
		${DISTNAME}-iso243-244.patch.gz \
		${DISTNAME}-iso244-245.patch.gz \
		${DISTNAME}-iso245-247.patch.gz \
		${DISTNAME}-iso247-248.patch.gz \
		lw${PORTVERSION}i248p10c.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kodama@ayame.mfd.cs.fujitsu.co.jp

GNU_CONFIGURE=	yes

MAN1=		lesw.1 leswkey.1

.include <bsd.port.mk>
