# New ports collection makefile for:	slimserver-lastfm
# Date created:				2005-12-31
# Whom:					freebsd-ports@varju.ca
#
# $FreeBSD$

PORTNAME=	lastfm
PORTVERSION=	1.13.1
CATEGORIES=	audio
MASTER_SITES=	http://petherton.pwp.blueyonder.co.uk/SlimServer/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	slimserver-
DISTNAME=	LastFM${DISTVERSION:S/.//g}

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	SlimServer plugin for playing last.fm radio

RUN_DEPENDS=	${LOCALBASE}/bin/softsqueeze:${PORTSDIR}/audio/slimserver \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

USE_PERL5=	yes
USE_ZIP=	yes
WRKSRC=		LastFM
NO_BUILD=	yes
CPIOARGS=	--quiet -pdum -R

SLIMDIR?=	slimserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	@cd ${WRKDIR} && \
	    ${FIND} LastFM | \
	    ${CPIO} ${CPIOARGS} ${BINOWN}:${BINGRP} ${PREFIX}/${SLIMDIR}/Plugins

.include <bsd.port.mk>
