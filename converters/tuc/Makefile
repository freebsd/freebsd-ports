PORTNAME=	tuc
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text to Unix Conversion
WWW=		http://www.whizkidtech.redprince.net/

# Converted from NO_CDROM
LICENSE=	TUC
LICENSE_NAME=	tuc
LICENSE_TEXT=	Author does not allow CD-ROM distribution
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BROKEN=		unfetchable 6 times in 2 weeks - Host does not resolve  

PLIST_FILES=	bin/tuc \
		share/man/man1/tuc.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tuc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tuc.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
