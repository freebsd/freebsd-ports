PORTNAME=	xshodou
PORTVERSION=	1.11
PORTREVISION=	4
CATEGORIES=	japanese tk
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese shodou program for X based on Tcl/Tk

USES=		tk

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${PREFIX}|g ; \
		 s|/usr/local/bin/wish|${WISH}|' ${WRKSRC}/xshodou
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${STAGEDIR}${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
