# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unmass
PORTVERSION=	0.9
CATEGORIES=	archivers
MASTER_SITES=	http://mirex.mypage.sk/FILES/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Extract game archives such as wad, dar, mea exe's, and many more

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/kdev

PLIST_FILES=	bin/unmass

post-patch:
.for f in ma.cpp massfs.h utools.h
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' ${WRKSRC}/src/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}_kdev \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
