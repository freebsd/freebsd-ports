# $FreeBSD$

PORTNAME=	deco
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://hartlich.com/deco/download/ \
		http://hartlich.com/deco/archive/download/:site2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-archive-1.6${EXTRACT_SUFX}:site2

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Program to extract various archive file formats

LICENSE=	GPLv3

RUN_DEPENDS=	arc:${PORTSDIR}/archivers/arc \
		arj:${PORTSDIR}/archivers/arj \
		cabextract:${PORTSDIR}/archivers/cabextract \
		dpkg:${PORTSDIR}/archivers/dpkg \
		lzop:${PORTSDIR}/archivers/lzop \
		7z:${PORTSDIR}/archivers/p7zip \
		rpm:${PORTSDIR}/archivers/rpm4 \
		rzip:${PORTSDIR}/archivers/rzip \
		unace:${PORTSDIR}/archivers/unace \
		unrar:${PORTSDIR}/archivers/unrar \
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
	@${FIND} ${STAGEDIR}${DATADIR} -type f -exec ${CHMOD} +x {} \;

.include <bsd.port.mk>
