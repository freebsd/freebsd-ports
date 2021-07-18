# Created by: G. Adam Stanislav <adam@whizkidtech.net>

PORTNAME=	tuc
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text to Unix Conversion

# Converted from NO_CDROM
LICENSE=	TUC
LICENSE_NAME=	tuc
LICENSE_TEXT=	Author does not allow CD-ROM distribution
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

PLIST_FILES=	bin/tuc \
		man/man1/tuc.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tuc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tuc.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
