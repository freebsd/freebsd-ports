# New ports collection makefile for:	kakasi
# Version required:		2.2.5
# Date created:			26 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	kakasi-2.2.5
PKGNAME=	ja-kakasi-2.2.5
CATEGORIES=	japanese
MASTER_SITES=	ftp://sunsite.sut.ac.jp/pub/asia-info/japanese-src/packages/ \
	ftp://ftp.kusastro.kyoto-u.ac.jp/pub/baba/wais/ \
		ftp://etlport.etl.go.jp/pub/mule/contrib/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/contrib/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/contrib/ \
		ftp://ftp.funet.fi/pub/gnu/funet/emacs/mule/contrib/ \
		ftp://ftp.iij.ad.jp/pub/misc/mule/contrib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} kakasidict.940620.gz \
		kakasi-ext.tar.gz

MAINTAINER=	max@FreeBSD.org

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX} kakasi-ext.tar.gz
WRKSRC=			${WRKDIR}/${DISTNAME}/src
PATCH_DIST_STRIP=	-p1
MANLANG=		ja
MAN1=			kakasi.1
post-extract:
	@${GZCAT} ${DISTDIR}/kakasidict.940620.gz > ${WRKSRC}/kakasidict

pre-patch:
	@${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/kakasi-ext/patch.kakasi-2.2.5

post-install:
.for f in mkkanwa atoc-conv rdic-conv
	@/usr/bin/strip ${PREFIX}/lib/kakasi/$f
.endfor
	${INSTALL_MAN} ${WRKSRC}/kakasi.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/kakasi
	${INSTALL_DATA} ${WRKSRC}/JISYO ${PREFIX}/share/doc/kakasi
	${INSTALL_DATA} ${WRKSRC}/../README* ${PREFIX}/share/doc/kakasi
	${INSTALL_DATA} ${WRKDIR}/kakasi-ext/KAKASI.DOC \
	  ${PREFIX}/share/doc/kakasi/kakasi-ext.doc
.endif

.include <bsd.port.mk>
