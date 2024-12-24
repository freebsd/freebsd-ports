PORTNAME=	vxtools
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.penguin.cz/pub/users/mhi/vxfs/

MAINTAINER=	mhi@penguin.cz
COMMENT=	Command-line utilities for reading Veritas Filesystem (VxFS)

DEPRECATED=	Dist files are no longer available as site returns NXDOMAIN
EXPIRATION_DATE=	2025-01-24

USES=		tar:bzip2 gmake
GNU_CONFIGURE=	yes

do-install:
.for f in vxls vxmount vxumount vxcat vxidump vxcd vxpwd prtvtoc
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/prtvtoc.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/vxmount.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/vxumount.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
