# New ports collection makefile for:	kon2
# Version required:     0.3
# Date created:         11 Apr 1997
# Whom:                 Makoto Matsushita <matusita@jp.freebsd.org>
#
# $Id: Makefile,v 1.15 1998/09/26 15:41:19 kuriyama Exp $
#

DISTNAME=	kon2-0.3
PKGNAME=	ja-kon2-0.3
CATEGORIES=	japanese
# note kon is only in first directory and fonts are only in second directory
MASTER_SITES=	ftp://ftp.tut.ac.jp/Linux/Packages/Utils/ \
		ftp://ftp.xfree86.org/pub/XFree86/3.3.2/untarred/xc/fonts/bdf/misc/ \
		ftp://ftp.iij.ad.jp/pub/X/XFree86/3.3.2/untarred/xc/fonts/bdf/misc/
DISTFILES=	kon2-0.3.tar.gz \
		k14.bdf 7x14rk.bdf \
		jiskan16.bdf 8x16rk.bdf

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

MAN1=		kon.1
MANLANG=	ja
EXTRACT_ONLY=	kon2-0.3.tar.gz

DOCDIR=		${PREFIX}/share/doc/kon2

.if defined(KONFONT)
.if (${KONFONT} == "16dot")
KON16FONT=Startup
.else if (${KONFONT} == "14dot")
KON14FONT=Startup
.endif
.endif

pre-fetch:
.if !defined(KONFONT)
	@${ECHO_MSG} "NOTE: You can select default kon font size."
	@${ECHO_MSG} "by adding \"KONFONT=<Font Size>\" to argument of make."
	@${ECHO_MSG} "<Font Size> must be \"16dot\" or \"14dot\"."
	@${ECHO_MSG} "KONFONT defalut value is \"16dot\"."
KON16FONT=Startup
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
