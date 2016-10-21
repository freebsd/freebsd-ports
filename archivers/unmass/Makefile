# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unmass
PORTVERSION=	0.92
CATEGORIES=	archivers
MASTER_SITES=	http://mirex.mypage.sk/FILES/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Extract game archives such as wad, dar, mea exe's, and many more

LICENSE=	GPLv2

USES=		gmake dos2unix
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/kdev_cmd

PLIST_FILES=	bin/unmass

CFLAGS+=	-DUNIX

post-extract:
	@${MV} ${WRKSRC}/../src/* ${WRKSRC}/src/

post-patch:
.for f in ma.cpp massfs.h utools.h
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' ${WRKSRC}/src/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}_kdev \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
