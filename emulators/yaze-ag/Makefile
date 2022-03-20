PORTNAME=	yaze-ag
DISTVERSION=	2.51.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.mathematik.uni-ulm.de/users/ag/yaze-ag/devel/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Z80 and CP/M-80 emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libreadline.so:devel/readline

USES=		compiler:c11

MAKEFILE=	Makefile_freebsd
MAKE_ENV=	BINDIR=${PREFIX}/bin \
		DESTDIR="${STAGEDIR}" \
		DOCDIR=${DOCSDIR} \
		DOCHTMLDIR=${DOCSDIR}/html \
		DSKDIR=${DATADIR}/disks \
		LIBDIR=${DATADIR} \
		LIBEXECDIR=${PREFIX}/libexec \
		MANDIR=${MAN1PREFIX}/man/man1 \
		OPTIMIZE="${CFLAGS}"

CONFLICTS_INSTALL=	cpmtools

OPTIONS_DEFINE=	DOCS

post-build:
		${REINPLACE_CMD} -e 's:%%DATADIR%%:${DATADIR}:' \
				 -e 's:%%DOCSDIR%%:${DOCSDIR}:' \
				 -e 's:%%LIBEXECDIR%%:${PREFIX}/libexec:' \
							${WRKSRC}/yaze.sh

.include <bsd.port.mk>
