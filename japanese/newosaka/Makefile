# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	newosaka
PORTVERSION=	1.0
CATEGORIES+=	japanese
MASTER_SITES=	PORTS_JP
DISTFILES=	new-osaka.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translator of Japanese EUC documents into Osaka language

BROKEN_FreeBSD_13=	ld: error: undefined symbol: gets

PLIST_FILES=	bin/osaka
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	(cd ${WRKSRC}; ${CC} ${CFLAGS} -o osaka osaka.c -I${WRKSRC})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/osaka ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
