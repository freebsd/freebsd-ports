# $FreeBSD$

DISTVERSION=	1.0.1-2768
DISTVERSIONSUFFIX=	-gd8b43dd
PORTREVISION=	0
PKGNAMESUFFIX=	-devel
# XXX Get from Debian once #697821 lands
MASTER_SITES=	https://bazaar.launchpad.net/~sergio-br2/${PORTNAME}/debian-sdl/download/1/${PORTNAME}.1-20140802045408-dd26dik367ztj5xg-8/:manpage
DISTFILES=	${PORTNAME}.1:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

GH_TAGNAME=	e22d7a5:lang a0b878f:ext_armips

CONFLICTS_INSTALL?=	${PORTNAME}-[0-9]*

LIB_DEPENDS=	libzip.so:${PORTSDIR}/archivers/libzip \
		libsnappy.so:${PORTSDIR}/archivers/snappy
USE_GL=		glew

EXCLUDE=	glew snappy libzip zlib
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}

MASTERDIR=	${.CURDIR}/../ppsspp
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

post-patch:	slave-post-patch
slave-post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' \
		${WRKSRC}/Qt/*.pr*

post-install:	slave-post-install
slave-post-install:
	${INSTALL_MAN} ${_DISTDIR}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
