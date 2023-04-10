PORTNAME=	tnftp
PORTVERSION=	20230409
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/tnftp/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Enhanced FTP client from NetBSD

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libedit ncurses ssl
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tnftp \
		man/man1/tnftp.1.gz

.include <bsd.port.mk>
