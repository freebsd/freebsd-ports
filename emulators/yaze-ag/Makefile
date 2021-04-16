# $FreeBSD$

PORTNAME=	yaze-ag
DISTVERSION=	2.51.0-rc1
CATEGORIES=	emulators
MASTER_SITES=	http://www.mathematik.uni-ulm.de/users/ag/yaze-ag/devel/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Z80 and CP/M-80 emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libreadline.so:devel/readline

USE_CSTD=	c11

MAKEFILE=	Makefile_freebsd
MAKE_ENV=	BINDIR=${PREFIX}/bin \
		DOCDIR=${DOCSDIR} \
		DOCHTMLDIR=${DOCSDIR}/html \
		DSKDIR=${DATADIR}/disks \
		LIBDIR=${DATADIR} \
		MANDIR=${MAN1PREFIX}/man/man1 \
		OPTIMIZE="${CFLAGS}" \
		STAGEDIR="${STAGEDIR}"

OPTIONS_DEFINE=	DOCS

post-build:
		${REINPLACE_CMD} -e 's:%%DATADIR%%:${DATADIR}:' \
				 -e 's:%%DOCSDIR%%:${DOCSDIR}:' \
				 -e 's:%%LIBEXECDIR%%:${PREFIX}/libexec:' \
							${WRKSRC}/yaze.sh

do-install-DOCS-on:
		${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} -f ${MAKEFILE} install-doc

.include <bsd.port.mk>
