# New ports collection makefile for:	webalizer
# Version required:	1.20
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.1.1.1 1998/07/13 00:13:21 steve Exp $

DISTNAME=	webalizer-1.20-07-src
PKGNAME=	de-webalizer-1.20
CATEGORIES=	german www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.sub.de/pub/approved/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

BIN1=		de-webalizer
MAN1=		de-webalizer.1
DOC1=		CHANGES COPYING Copyright INSTALL \
		README country-codes.txt webalizer.LSM
WRKSRC=		${WRKDIR}

post-configure:
	@echo "config german"
	@${ECHO_MSG} "===> customizing for german"
	@cd ${WRKSRC}; ${LN} -sf webalizer_lang.german webalizer_lang.h

do-install:
.for i in ${BIN1}
	@${INSTALL_SCRIPT} ${WRKSRC}/webalizer ${PREFIX}/bin/${i}
.endfor

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/webalizer.1 ${PREFIX}/man/man1/${i}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/de-webalizer
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/de-webalizer/${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/de-webalizer
.for i in msfree.gif sample.conf
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/de-webalizer/${i}
.endfor
	@if [ ! -f ${PREFIX}/etc/webalizer.conf-dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.conf \
			${PREFIX}/etc/webalizer.conf-dist ; \
	fi

.include <bsd.port.mk>
