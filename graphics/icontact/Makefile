PORTNAME=	icontact
PORTVERSION=	1.5
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.panix.com/~mbh/icontact/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Combines multiples images to create a single customisable image
WWW=		https://www.panix.com/~mbh/projects.html

RUN_DEPENDS=	${LOCALBASE}/bin/ppmmake:graphics/netpbm

USES=		jpeg:run shebangfix
SHEBANG_FILES=	icontact

post-patch:
	${REINPLACE_CMD} "s|CC=cc|CC=${CC}|g; s|CFLAGS=-O|CFLAGS=${CFLAGS}|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/icontact ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xvtoppm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icontact.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/xvtoppm.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
