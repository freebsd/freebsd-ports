# New ports collection makefile for: 	gn(Gon's Newsreader with gnspool)
# Version required:			1.40
# Date created:				14 Feb. 1997
# Whom:					Kiroh HARADA <kiroh@kh.rim.or.jp>
#
# $Id$
#

DISTNAME=	gn-1.40
PKGNAME=	ja-gn-gnspool-1.40
CATEGORIES=	japanese news
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/misc/gn/

MAINTAINER=	kiroh@kh.rim.or.jp

WRKSRC=		${WRKDIR}/${DISTNAME}/src

pre-configure:
	@${CP} ${WRKDIR}/${DISTNAME}/mkfiles/unix/common ${WRKSRC}/Makefile
	@${PATCH} -d ${WRKSRC} < ${FILESDIR}/Makefile.patch
	@${SED} s+@PREFIX@+${PREFIX}+ ${FILESDIR}/site.def.in \
		> ${WRKSRC}/site.def
	@(cd ${WRKSRC}; ${MAKE} configur)

do-configure:
	@(cd ${WRKSRC}; yes | ./configur)

post-install:
.for f in gn gnspool gninews gnmail
	@strip ${PREFIX}/bin/$f
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gn-gnspool
	@${CP} -R ${WRKDIR}/${DISTNAME}/docs.jp/* ${PREFIX}/share/doc/gn-gnspool
	@${CP} ${FILESDIR}/Changes.FreeBSD.port ${PREFIX}/share/doc/gn-gnspool
.endif
.if !defined(NOMANCOMPRESS)
	@gzip -9nf ${PREFIX}/man/ja/cat1/gn.1 \
	${PREFIX}/man/ja/cat1/gnspool.1 ${PREFIX}/man/ja/cat1/gnloops.1
.endif
	@${MKDIR} ${PREFIX}/share/examples/gn-gnspool
	@${CP} ${FILESDIR}/_gnrc ${PREFIX}/share/examples/gn-gnspool
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
