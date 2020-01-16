# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lcab
PORTVERSION=	1.0b12
CATEGORIES=	archivers
MASTER_SITES=	DEBIAN
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Microsoft .CABinet file creator

LICENSE=	GPLv2+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/lcab share/man/man1/${PORTNAME}.1.gz

pre-build:
	@${REINPLACE_CMD} -e 's|1.0b11|1.0b12|' ${WRKSRC}/mytypes.h
	@${REINPLACE_CMD} -e 's|1.0b8|1.0b12|' \
		-e '/http:\/\/www.geekshop.be\/rien\/lcab\//d' \
		${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
