# ports collection makefile for:   xhime
# Version required:    1.51
# Date created:        25 August 1998
# Whom:                Seiichirou Hiraoka
#
# $FreeBSD$
#

DISTNAME=	xhime151
PKGNAME=	xhime-1.51
CATEGORIES=	games
MASTER_SITES=	http://www.tcp-ip.or.jp/~shochan/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	flathill@FreeBSD.org

WRKSRC=		${WRKDIR}/xhime1.51
USE_IMAKE=	yes
MANCOMPRESSED=	yes
MANLANG=	. ja
MAN6=		xhime.6

NO_CDROM=	'contains commercial character data'

FETCH_BEFORE_ARGS=	-b

post-install:
	strip ${PREFIX}/bin/xhime
	${INSTALL_MAN} ${WRKSRC}/xhime-man.euc \
		${PREFIX}/man/ja/man6
	${MV} ${PREFIX}/man/ja/man6/xhime-man.euc ${PREFIX}/man/ja/man6/xhime.6
	${GZIP_CMD} ${PREFIX}/man/ja/man6/xhime.6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/xhime
	@(cd ${WRKSRC};\
	${INSTALL_MAN} xhime-doc.euc xhime.doc rh110-doc.euc \
		${PREFIX}/share/doc/ja/xhime; \
	)
.endif

.include <bsd.port.mk>
