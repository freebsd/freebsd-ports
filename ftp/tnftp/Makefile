PORTNAME=	tnftp
DISTVERSION=	20230507
CATEGORIES=	ftp
MASTER_SITES=	https://cdn.netbsd.org/pub/NetBSD/misc/tnftp/ \
		https://ftp.uni-erlangen.de/netbsd/misc/tnftp/ \
		https://ftp.jaist.ac.jp/pub/NetBSD/misc/tnftp/ \
		https://ftp.netbsd.org/pub/NetBSD/misc/tnftp/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Enhanced FTP client from NetBSD
WWW=		https://ftp.netbsd.org/pub/NetBSD/misc/tnftp/

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libedit ncurses ssl
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tnftp \
		man/man1/tnftp.1.gz

.include <bsd.port.mk>
