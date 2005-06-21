# New ports collection makefile for:	Natural Selection Server
# Date created:				Tue Nov 12 03:27:08 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	1.0.4
PORTREVISION=	1
MASTER_SITES=	http://files.games.eftel.com/halflife/ns/ \
		http://www.jetstreamgames.co.nz/files/pub/halflife/NaturalSelection/ \
		ftp://ftp2.extreme-players.de/hl/mod/ns/ \
		http://files.redphive.org/:PATCH
DISTFILES=	ns_v1_linux_dedicated_server.tar.gz \
		ns-v${PORTVERSION:S/.//g}.zip:PATCH
EXTRACT_ONLY=	ns_v1_linux_dedicated_server.tar.gz

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Half-Life mod Natural Selection full server package for Linux

UNZIP?=		${LOCALBASE}/bin/unzip

slaveport-post-extract:
	@cd ${WRKSRC} && ${UNZIP} -a -o -qq ${DISTDIR}/ns-v${PORTVERSION:S/.//g}.zip

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"
