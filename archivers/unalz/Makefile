# New ports collection makefile for:	unalz
# Date created:		23 October 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	unalz
PORTVERSION=	0.65
CATEGORIES=	archivers
MASTER_SITES=	http://www.kipple.pe.kr/win/unalz/ \
		http://www.c-s.li/ports/
EXTRACT_SUFX=	.tgz

MAINTAINER=	c-s@c-s.li
COMMENT=	Extracts AlZip archives

LICENSE_FILE=	${WRKSRC}/readme.txt

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
