# New ports collection makefile for: 	gn(Gon's Newsreader with gnspool)
# Date created:				14 Feb. 1997
# Whom:					Kiroh HARADA <kiroh@kh.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	gn-gnspool
PORTVERSION=	1.40
CATEGORIES=	japanese news
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/misc/gn/
DISTNAME=	gn-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Japanese Newsreader with Local Spool Support

# The program ``configure'' sometimes issue questions and
# batch-mode build would fail.
IS_INTERACTIVE=	yes
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
	@${GZIP_CMD} ${PREFIX}/man/ja/cat1/gn.1 \
	${PREFIX}/man/ja/cat1/gnspool.1 ${PREFIX}/man/ja/cat1/gnloops.1
.endif
	@${MKDIR} ${PREFIX}/share/examples/gn-gnspool
	@${CP} ${FILESDIR}/_gnrc ${PREFIX}/share/examples/gn-gnspool
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
