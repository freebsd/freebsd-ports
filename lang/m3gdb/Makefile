# New ports collection makefile for:   m3gdb
# Version required:    4.17
# Date created:        17 February 1999
# Whom:                wagner@luthien.in-berlin.de
#
# $FreeBSD$
#

DISTNAME=      m3gdb-4.17
CATEGORIES=    lang devel
MASTER_SITES=  http://www.freebsd.org/~jdp/distfiles/

MAINTAINER=    jdp@FreeBSD.ORG

MAN1=          m3gdb.1
MANCOMPRESSED= yes

pre-fetch:
	@if [ ! -d /usr/src/contrib/gdb ]; then \
	    ${ECHO_MSG} "To build this port you must have the FreeBSD" \
		"sources in \"/usr/src\"."; \
	    exit 1; \
	fi

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make depend
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make libbuild

.include <bsd.port.mk>
