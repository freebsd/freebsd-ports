# New ports collection makefile for:	webalizer
# Version required:	1.22
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

DISTNAME=	webalizer-1.22-06-src
PKGNAME=	de-webalizer-1.22.6
CATEGORIES=	german www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.sub.de/pub/approved/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

WEBALIZER_LANG= german
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-language=${WEBALIZER_LANG}
BIN1=		de-webalizer
MAN1=		de-webalizer.1
DOC1=		CHANGES COPYING Copyright INSTALL \
		README country-codes.txt webalizer.LSM
WRKSRC=		${WRKDIR}/webalizer-1.22-06

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
.for i in msfree.gif sample.conf webalizer.gif
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/de-webalizer/${i}
.endfor
	@if [ ! -f ${PREFIX}/etc/de-webalizer.conf-dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.conf \
			${PREFIX}/etc/de-webalizer.conf-dist ; \
	fi

.include <bsd.port.mk>
