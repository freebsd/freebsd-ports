# New ports collection makefile for:	unalz
# Date created:		23 October 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	unalz
PORTVERSION=	0.31
CATEGORIES=	archivers
MASTER_SITES=	http://www.kipple.pe.kr/win/unalz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Extracts AlZip archives

USE_ICONV=	yes
PLIST_FILES=	bin/unalz
MAKEFILE=	Makefile.freebsd
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${PREFIX}/bin

.include <bsd.port.mk>
