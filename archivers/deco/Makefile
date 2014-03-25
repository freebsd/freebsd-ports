# $FreeBSD$

PORTNAME=	deco
PORTVERSION=	1.6.3
CATEGORIES=	archivers
MASTER_SITES=	http://hartlich.com/deco/download/:site1 \
		http://hartlich.com/deco/archive/download/:site2
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:site1 \
		${PORTNAME}-archive-1.6.tar.gz:site2

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Program to extract various archive file formats

LICENSE=	GPLv3

RUN_DEPENDS=	arc:${PORTSDIR}/archivers/arc \
		arj:${PORTSDIR}/archivers/arj \
		cabextract:${PORTSDIR}/archivers/cabextract \
		dpkg:${PORTSDIR}/archivers/dpkg \
		lzop:${PORTSDIR}/archivers/lzop \
		7z:${PORTSDIR}/archivers/p7zip \
		rpm:${PORTSDIR}/archivers/rpm \
		rzip:${PORTSDIR}/archivers/rzip \
		unace:${PORTSDIR}/archivers/unace \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		zoo:${PORTSDIR}/archivers/zoo \
		flac:${PORTSDIR}/audio/flac

CONFLICTS=	deco-[0-9]*

post-patch:
	@${CP} ${FILESDIR}/extract ${WRKDIR}/${PORTNAME}-archive-1.6/x/"tar\.xz"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
	cd ${WRKDIR}/${PORTNAME}-archive-1.6 && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deco ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in CREDITS LICENSE Makefile NEWS README config.mk
	${RM} -rf ${WRKSRC}/../${PORTNAME}-archive-1.6/${i}
.endfor
	@cd ${WRKDIR}/${PORTNAME}-archive-1.6/x/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
