# New ports collection makefile for:	kakasi
# Version required:		2.2.5
# Date created:			26 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1996/09/17 15:07:26 max Exp $
#

DISTNAME=	kakasi-2.2.5
PKGNAME=	jp-kakasi-2.2.5
CATEGORIES+=	japanese
MASTER_SITES=	ftp://sunsite.sut.ac.jp/pub/asia-info/japanese-src/packages/ \
		ftp://etlport.etl.go.jp/pub/mule/contrib/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/contrib/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/contrib/ \
		ftp://ftp.funet.fi/pub/gnu/funet/emacs/mule/contrib/ \
		ftp://ftp.iij.ad.jp/pub/misc/mule/contrib/
DISTFILES =	kakasi-2.2.5.tar.gz kakasidict.940620.gz

MAINTAINER=	max@FreeBSD.ORG

EXTRACT_ONLY=	kakasi-2.2.5.tar.gz
WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-extract:
	@gzip -cd ${DISTDIR}/kakasidict.940620.gz > ${WRKSRC}/kakasidict

.include <bsd.port.mk>
