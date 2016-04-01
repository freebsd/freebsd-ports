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

RUN_DEPENDS=	arc:archivers/arc \
		arj:archivers/arj \
		cabextract:archivers/cabextract \
		dpkg:archivers/dpkg \
		lzop:archivers/lzop \
		7z:archivers/p7zip \
		rpm:archivers/rpm4 \
		rzip:archivers/rzip \
		unace:archivers/unace \
		unrar:archivers/unrar \
		zoo:archivers/zoo \
		flac:audio/flac

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
