PORTNAME=	pstreams
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Release%200.8.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ utility for simple IOStream-based IPC
WWW=		http://pstreams.sourceforge.net/

LICENSE=	LGPL3

USES=		gmake
MAKE_ENV+=	INSTALL_PREFIX=${PREFIX}
NO_BUILD=	yes

PLIST_FILES=	include/pstreams/pstream.h

.include <bsd.port.mk>
