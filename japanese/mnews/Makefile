# New ports collection makefile for:	mnews
# Version required:		1.19PL2
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1997/02/15 17:21:26 max Exp $
#

DISTNAME=	mnews120
PKGNAME=	ja-mnews-1.20
CATEGORIES=	japanese news
MASTER_SITES=	ftp://ftp.mei.co.jp/free/Network/news/readers/

MAINTAINER=	kiroh@kh.rim.or.jp

WRKSRC=		${WRKDIR}/mnews-1.20/build
MAN1=		mnews.1
MANLANG=	ja_JP.EUC

DOCS=		FAQ.doc board.doc gnspool.doc mnews.doc prerel.doc	\
		present.doc read1ST.doc readme.doc update.doc youbin.doc
SAMPLES=	_mnews.smp jnames.fj jnames.jp jnames.smp jnames.tnn

do-configure:
	@for f in Makefile site_dep.h ; do \
	  ${SED} s+@PREFIX@+${PREFIX}+ ${FILESDIR}/$$f.in > ${WRKSRC}/$$f ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mnews ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/mnews
	${INSTALL_DATA} ${WRKSRC}/../etc/jnames.fj ${PREFIX}/lib/mnews/jnames
	${MKDIR} ${PREFIX}/share/examples/mnews
.for f in ${SAMPLES}
	${INSTALL_DATA} ${WRKSRC}/../etc/$f ${PREFIX}/share/examples/mnews
.endfor
	${INSTALL_MAN} ${WRKSRC}/../doc/mnews.1 ${PREFIX}/man/ja_JP.EUC/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mnews
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../doc/$f ${PREFIX}/share/doc/mnews
.endfor
.endif

post-install:
.if !defined(BATCH)
	@(while [ X$$domain = X ]; do					\
	    read -p "Enter the domain name of this host>" domain ;	\
	  done;								\
	echo $$domain > ${PREFIX}/lib/mnews/default-domain)
.else
	@echo "Now, you need to make sure ${PREFIX}/lib/mnews/default-domain"
	@echo "contains correct domain name."
	@echo my.domain.com > ${PREFIX}/lib/mnews/default-domain
.endif
	@echo "Please refer to the files in:"
	@echo "${PREFIX}/share/doc/mnews & ${PREFIX}/share/examples/mnews."

.include <bsd.port.mk>
