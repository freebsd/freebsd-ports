# Created by: Martin Hinner
# $FreeBSD$

PORTNAME=	vxtools
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.penguin.cz/pub/users/mhi/vxfs/

MAINTAINER=	mhi@penguin.cz
COMMENT=	Command-line utilities for reading Veritas Filesystem (VxFS)

USES=		tar:bzip2 gmake
GNU_CONFIGURE=	yes

do-install:
.for f in vxls vxmount vxumount vxcat vxidump vxcd vxpwd prtvtoc
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/prtvtoc.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/vxmount.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/vxumount.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
