# Created by: Joel Sutton <jsutton@bbcon.com.au>
# $FreeBSD$

PORTNAME=	aftp
PORTVERSION=	1.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.apple.asimov.net/pub/apple_II/utility/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ftp-like shell for accessing Apple II disk images

BROKEN=		unfetchable

PLIST_FILES=	bin/aftp man/man1/aftp.1.gz

post-patch:
	${REINPLACE_CMD} -e 's|^CC=.*|CC=${CC} ${CPPFLAGS} ${CFLAGS}|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${FILESDIR}/aftp.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
