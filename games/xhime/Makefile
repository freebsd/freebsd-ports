# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	xhime
PORTVERSION=	1.51
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.tcp-ip.or.jp/~shochan/linux/
DISTFILES=	xhime151.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resident Himechan for X Window System

WRKSRC=		${WRKDIR}/xhime1.51
USES=		imake
USE_XORG=	x11 xext

NO_CDROM=	Contains commercial character data

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xhime
	${INSTALL_MAN} ${WRKSRC}/xhime-man.euc \
		${STAGEDIR}${PREFIX}/man/ja/man6
	${MV} ${STAGEDIR}${PREFIX}/man/ja/man6/xhime-man.euc ${STAGEDIR}${PREFIX}/man/ja/man6/xhime.6
	#${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/ja/man6/xhime.6
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/xhime
	@(cd ${WRKSRC};\
	${INSTALL_DATA} xhime-doc.euc xhime.doc rh110-doc.euc \
		${STAGEDIR}${PREFIX}/share/doc/ja/xhime; \
	)

.include <bsd.port.mk>
