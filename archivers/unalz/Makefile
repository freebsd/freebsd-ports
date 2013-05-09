# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	unalz
PORTVERSION=	0.65
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.kipple.pe.kr/win/unalz/ \
		http://www.c-s.li/ports/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracts AlZip archives

LICENSE_FILE=	${WRKSRC}/readme.txt

USES=		iconv
PLIST_FILES=	bin/unalz
MAKEFILE=	Makefile.freebsd
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/unalz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${PREFIX}/bin

.include <bsd.port.mk>
