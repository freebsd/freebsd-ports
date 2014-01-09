# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	tuc
PORTVERSION=	1.10
CATEGORIES=	converters
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text to Unix Conversion

NO_CDROM=	Author does not allow CD-ROM distribution
PLIST_FILES=	bin/tuc \
		man/man1/tuc.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tuc ${STAGEDIR}${PREFIX}/bin
	$(INSTALL_MAN) ${WRKSRC}/tuc.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
