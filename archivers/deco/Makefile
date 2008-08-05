# New ports collection makefile for:	deco
# Date created:		06 May 2008
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deco
PORTVERSION=	1.4
CATEGORIES=	archivers
MASTER_SITES=	http://hartlich.com/deco/download/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A program to extract various archive file formats

RUN_DEPENDS=	arc:${PORTSDIR}/archivers/arc \
		arj:${PORTSDIR}/archivers/arj \
		cabextract:${PORTSDIR}/archivers/cabextract \
		dpkg:${PORTSDIR}/archivers/dpkg \
		lzma:${PORTSDIR}/archivers/lzmautils \
		lzop:${PORTSDIR}/archivers/lzop \
		7z:${PORTSDIR}/archivers/p7zip \
		rpm:${PORTSDIR}/archivers/rpm \
		unace:${PORTSDIR}/archivers/unace \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		zoo:${PORTSDIR}/archivers/zoo \
		flac:${PORTSDIR}/audio/flac

NO_BUILD=	yes

CONFLICTS=	deco-[0-9]*

.include <bsd.port.mk>
