# New ports collection makefile for:	kon2
# Version required:     0.3
# Date created:         11 Apr 1997
# Whom:                 Makoto Matsushita <matusita@jp.freebsd.org>
#
# $Id: Makefile,v 1.13 1997/09/19 19:27:45 max Exp $
#

DISTNAME=	kon2-0.3
PKGNAME=	ja-kon2-0.3
CATEGORIES=	japanese
# note kon is only in first directory and fonts are only in second directory
MASTER_SITES=	ftp://ftp.tut.ac.jp/Linux/Packages/Utils/ \
		ftp://ftp.iij.ad.jp/pub/X/XFree86/XFree86/3.3.1/untarred/xc/fonts/bdf/misc/
DISTFILES=	kon2-0.3.tar.gz k14.bdf 7x14rk.bdf

MAINTAINER=	hideyuki@sat.t.u-tokyo.ac.jp

MAN1=		kon.1
MANLANG=	ja
EXTRACT_ONLY=	kon2-0.3.tar.gz

DOCDIR=		${PREFIX}/share/doc/kon2

pre-build:
	${SED} -e 's,%%PREFIX%%,${PREFIX},' \
	  -e 's,%%DISTDIR%%,${DISTDIR},' \
	  ${FILESDIR}/dotconfig > ${WRKSRC}/.config
	@(cd ${WRKSRC}; ${MAKE} -f Makefile.FreeBSD config)

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/kon.1 ${PREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/README ${WRKSRC}/doc/README.FreeBSD \
		${DOCDIR}
.endif

.include <bsd.port.mk>
