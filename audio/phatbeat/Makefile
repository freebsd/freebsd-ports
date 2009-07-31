# New ports collection makefile for:	PhatBeat
# Date created:			22 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		phatbeat
PORTVERSION=		1.1
PORTREVISION=	5
CATEGORIES=		audio
MASTER_SITES=		http://www.postreal.org/files/
DISTNAME=		PhatBeat-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A beat counter

USE_SDL=		sdl image
MAN1=			phatbeat.1

MAKE_ENV=		MKDIR="${MKDIR}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
