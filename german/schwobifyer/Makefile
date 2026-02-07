PORTNAME=	schwobifyer
PORTVERSION=	20050730
CATEGORIES=	german
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility for translating German into the Schwaebisch dialect
WWW=		http://unimut.fsk.uni-heidelberg.de/schwob.html

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/schwobifyer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
