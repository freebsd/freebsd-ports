# New ports collection makefile for:	mnews
# Version required:		1.19PL2
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1996/11/11 10:12:28 max Exp $
#

DISTNAME=	mnews119
PKGNAME=	jp-mnews-1.19.2
CATEGORIES=	japanese news
MASTER_SITES=	ftp://ftp.mei.co.jp/free/Network/news/readers/
DISTFILES=	mnews119.tar.gz mnews119_119PL1.tar.gz mnews119PL1_PL2.tar.gz

MAINTAINER=	max@FreeBSD.ORG

NO_WRKSUBDIR=	yes
PATCH_DIST_STRIP= -p1
MAN1=		mnews.1
MANLANG=	ja_JP.EUC

DOCS=		FAQ.doc board.doc mnews.doc prerel.doc		\
		present.doc read1ST.doc readme.doc update.doc 
SAMPLES=	jnames.fj jnames.jp jnames.smp jnames.tnn

pre-patch:
	@for f in mnews119PL1.patch mnews119PL2.patch; do \
	  ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/$$f ; done

do-configure:
	@for f in Makefile site_dep.h ; do \
	  sed s+@PREFIX@+${PREFIX}+ ${FILESDIR}/$$f.in > ${WRKSRC}/$$f ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mnews ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/mnews
	${INSTALL_DATA} ${WRKSRC}/jnames.fj ${PREFIX}/lib/mnews/jnames
	${MKDIR} ${PREFIX}/share/examples/mnews
.for f in ${SAMPLES}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/examples/mnews
.endfor
	${INSTALL_MAN} ${WRKSRC}/mnews.1 ${PREFIX}/man/ja_JP.EUC/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mnews
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/mnews
.endfor
.endif

post-install:
.if !defined(BATCH)
	@(while [ X$$domain = X ]; do					\
	    echo -n "Enter the domain name of this host>"; read domain ;	\
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
