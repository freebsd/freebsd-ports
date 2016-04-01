# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	icontact
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.panix.com/~mbh/icontact/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Combines multiples images to create a single customisable image

RUN_DEPENDS=	${LOCALBASE}/bin/ppmmake:graphics/netpbm

USES=		jpeg:run shebangfix
SHEBANG_FILES=	icontact

post-patch:
	${REINPLACE_CMD} "s|CC=cc|CC=${CC}|g; s|CFLAGS=-O|CFLAGS=${CFLAGS}|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/icontact ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xvtoppm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icontact.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/xvtoppm.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
