# New ports collection makefile for:	deco
# Date created:		06 May 2008
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deco
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://hartlich.com/deco/download/:site1 \
		http://hartlich.com/deco/archive/download/:site2
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:site1 \
		${PORTNAME}-archive-1.4.tar.gz:site2

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A program to extract various archive file formats

RUN_DEPENDS=	arc:${PORTSDIR}/archivers/arc \
		arj:${PORTSDIR}/archivers/arj \
		cabextract:${PORTSDIR}/archivers/cabextract \
		dpkg:${PORTSDIR}/archivers/dpkg \
		lzma:${PORTSDIR}/archivers/xz \
		lzop:${PORTSDIR}/archivers/lzop \
		7z:${PORTSDIR}/archivers/p7zip \
		rpm:${PORTSDIR}/archivers/rpm \
		rzip:${PORTSDIR}/archivers/rzip \
		unace:${PORTSDIR}/archivers/unace \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		zoo:${PORTSDIR}/archivers/zoo \
		flac:${PORTSDIR}/audio/flac

NO_LATEST_LINK=	yes
CONFLICTS=	deco-[0-9]*

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
	cd ${WRKDIR}/${PORTNAME}-archive-1.4 && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/deco ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for i in CREDITS LICENSE Makefile NEWS README config.mk
	${RM} -rf ${WRKSRC}/../${PORTNAME}-archive-1.4/${i}
.endfor
	@cd ${WRKDIR}/${PORTNAME}-archive-1.4/ && ${CP} -pPR * ${DATADIR}

.include <bsd.port.mk>
