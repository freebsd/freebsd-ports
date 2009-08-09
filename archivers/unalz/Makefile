# New ports collection makefile for:	unalz
# Date created:		23 October 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	unalz
PORTVERSION=	0.63
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
WRKSRC=		${WRKDIR}/unalz

pre-patch:
	cd ${WRKSRC} && for f in `find . -name '*.c' -o -name '*.h'`; do \
		${TR} -d '\015' < ${WRKSRC}/$$f > ${WRKSRC}/$$f.tmp && \
		${MV} -f ${WRKSRC}/$$f.tmp ${WRKSRC}/$$f; \
	done
	${REINPLACE_CMD} -e 's|CPP = g++|CPP = ${CXX}|' \
			-e "s|CC  =|CC  ?=|" \
			${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${PREFIX}/bin

.include <bsd.port.mk>
