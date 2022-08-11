PORTNAME=	sjeng
PORTVERSION=	11.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://sjeng.org/ftp/
DISTNAME=	Sjeng-Free-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chess engine supporting chess variations

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgdbm.so:databases/gdbm

USES=		localbase dos2unix
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sjeng

.include <bsd.port.mk>
