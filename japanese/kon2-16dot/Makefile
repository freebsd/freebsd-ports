# New ports collection makefile for:	kon2 with 16dot font
# Version required:     0.3
# Date created:         11 Apr 1997
# Whom:                 Makoto Matsushita <matusita@jp.freebsd.org>
#
# $Id: Makefile,v 1.19 1998/11/20 04:14:27 asami Exp $
#

DISTNAME=	kon2-0.3
PKGNAME=	ja-kon2-${KONFONT}-0.3
CATEGORIES=	japanese
# note kon is only in first directory and fonts are only in second directory
MASTER_SITES=	ftp://ftp.tut.ac.jp/Linux/Packages/Utils/ \
		ftp://ftp.xfree86.org/pub/XFree86/3.3.2/untarred/xc/fonts/bdf/misc/ \
		ftp://ftp.iij.ad.jp/pub/X/XFree86/3.3.2/untarred/xc/fonts/bdf/misc/
DISTFILES=	kon2-0.3.tar.gz \
		k14.bdf 7x14rk.bdf \
		jiskan16.bdf 8x16rk.bdf

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

ONLY_FOR_ARCHS=	i386

MAN1=		kon.1
MANLANG=	ja
EXTRACT_ONLY=	kon2-0.3.tar.gz

DOCDIR=		${PREFIX}/share/doc/kon2

.if !defined(KONFONT)
KONFONT=16dot
KON16FONT=Startup
.elif (${KONFONT} == "14dot")
KON14FONT=Startup
.elif (${KONFONT} != "16dot")
.BEGIN:
	@${ECHO} "Error: \$${KONFONT} (\"${KONFONT}\") should be either \"14dot\" or \"16dot\"."
	@${FALSE}
.endif

pre-build:
	${SED} -e 's,%%PREFIX%%,${PREFIX},' \
	  -e 's,%%DISTDIR%%,${DISTDIR},' \
	  ${FILESDIR}/dotconfig > ${WRKSRC}/.config
	@(cd ${WRKSRC}; ${MAKE} -f Makefile.FreeBSD config)
	@for i in kon.cfg.FreeBSD doc/kon.1; do\
		${MV} -f ${WRKSRC}/$${i} ${WRKSRC}/$${i}.in ;\
		${SED} -e "s;@@PREFIX@@;${PREFIX};g" -e "s;@@KON16FONT@@;${KON16FONT};g" -e "s;@@KON14FONT@@;${KON14FONT};g" ${WRKSRC}/$${i}.in > ${WRKSRC}/$${i} ;\
	done

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/kon.1 ${PREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/README ${WRKSRC}/doc/README.FreeBSD \
		${DOCDIR}
.endif

.include <bsd.port.mk>
