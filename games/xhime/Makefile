PORTNAME=	xhime
PORTVERSION=	1.51
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.tcp-ip.or.jp/~shochan/linux/
DISTFILES=	xhime151.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resident Himechan for X Window System
WWW=		https://www.tcp-ip.or.jp/~shochan/linux/xhime.html

# Converted from NO_CDROM
LICENSE=	xhime
LICENSE_NAME=	xhime
LICENSE_TEXT=	Contains commercial character data
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

WRKSRC=		${WRKDIR}/xhime1.51
USES=		imake xorg
USE_XORG=	x11 xext

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/xhime
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man6
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xhime
	${INSTALL_MAN} ${WRKSRC}/xhime-man.euc \
		${STAGEDIR}${PREFIX}/share/man/ja/man6
	${MV} ${STAGEDIR}${PREFIX}/share/man/ja/man6/xhime-man.euc ${STAGEDIR}${PREFIX}/share/man/ja/man6/xhime.6
	#${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/ja/man6/xhime.6
	@(cd ${WRKSRC};\
		${INSTALL_DATA} xhime-doc.euc xhime.doc rh110-doc.euc \
			${STAGEDIR}${PREFIX}/share/doc/ja/xhime; \
	)

.include <bsd.port.mk>
