# New ports collection makefile for:	unalz
# Date created:		23 October 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	unalz
PORTVERSION=	0.20
CATEGORIES=	archivers
MASTER_SITES=	http://www.kipple.pe.kr/win/unalz/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Extracts AlZip archives

USE_REINPLACE=	yes
PLIST_FILES=	bin/unalz
MAKEFILE=	makefile
MAKE_ENV=	CC="${CC} ${CFLAGS}" CPP="${CXX} ${CXXFLAGS}"

post-patch:
.for f in UnAlz.cpp UnAlz.h
	${REINPLACE_CMD} 's/SIG_ERR/ALZ_SIG_ERR/g' ${WRKSRC}/$f
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${PREFIX}/bin

.include <bsd.port.mk>
