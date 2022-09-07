PORTNAME=	mph
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	SUNSITE/devel/lang/c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimal perfect hashing code generator
WWW=		https://www.ibiblio.org/pub/Linux/devel/lang/c/

BIN_FILES=	emitc mph mphm
PLIST_FILES=	bin/emitc bin/mph bin/mphm

do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
