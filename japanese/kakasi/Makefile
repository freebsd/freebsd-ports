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
MASTER_SITES=  ${MASTER_SITE_PORTS_JP}
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
