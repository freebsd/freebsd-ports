PORTNAME=	xfireworks
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fireworks on X
WWW=		https://kozos.jp/myfreesoft/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		xorg
USE_XORG=	x11

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfireworks ${STAGEDIR}${PREFIX}/bin/xfireworks
	${INSTALL_MAN} ${WRKSRC}/xfireworks.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/xfireworks.conf ${STAGEDIR}${PREFIX}/etc/xfireworks.conf.sample

.include <bsd.port.post.mk>
