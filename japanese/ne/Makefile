# New ports collection makefile for:    nxedit
# Version required:    3.00p17
# Date created:        15 Nov 1999
# Whom:                SASAKI Shunsuke <ele@pop17.odn.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	ne-3.00pre17
PKGNAME=	ja-ne-3.00p17
CATEGORIES=	japanese editors
MASTER_SITES=	http://www3.justnet.ne.jp/~ele/

MAINTAINER=	ele@pop17.odn.ne.jp

WRKSRC=		${WRKDIR}/ne
GNU_CONFIGURE=	yes
MAN1=		ne.1
MANLANG=	ja
MANCOMPRESSED=	no
DOCS=		BUGS.jp HISTORY.jp INSTALL.jp README.jp
MAKE_ENV=	LANG=${MANLANG}

post-install:
	strip ${PREFIX}/bin/ne

.if !defined(NOPORTDOC)
	@${MKDIR} ${PREFIX}/share/doc/ne
	@for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ne; \
	done
.endif

.include <bsd.port.mk>
