PORTNAME=	newosaka
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES+=	japanese
MASTER_SITES=	PORTS_JP
DISTFILES=	new-osaka.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translator of Japanese EUC documents into Osaka language

PLIST_FILES=	bin/osaka
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	(cd ${WRKSRC}; ${CC} ${CFLAGS} -o osaka osaka.c -I${WRKSRC})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/osaka ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
