# New ports collection makefile for:	e2ps
# Date created:		27 Nov 1998
# Whom:			Daisuke Kawahara <kawahara@pine.kuee.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	e2ps
PORTVERSION=	4.34
CATEGORIES=	japanese print
MASTER_SITES=	http://wt1.ld.infoseek.co.jp/sources/

MAINTAINER=	kawahara@pine.kuee.kyoto-u.ac.jp
COMMENT=	Text file to postscript converter (with Japanese support)

USE_BZIP2=	yes
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

.include <bsd.port.pre.mk>

post-patch:
		cd ${WRKSRC} && \
		mv ps-font.c ps-font.c.orig && \
		${SED} -e '/Times-Roman$$/,/^Gothic-Medium.Katakana$$/{s,$$,\\,;}' ps-font.c.orig > ps-font.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e2ps ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/e2ps ${PREFIX}/bin/e2lpr
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} README.euc README.english ${DOCDIR}
.endif

.include <bsd.port.post.mk>
