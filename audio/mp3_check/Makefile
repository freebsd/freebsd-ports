# New ports collection makefile for:	mp3_check
# Date created:				24 Oct 2000
# Whom:					ericb@thedeepsky.com
#
# $FreeBSD$
#

PORTNAME=	mp3_check
PORTVERSION=	1.98
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mp3check

MAINTAINER=	ericb@thedeepsky.com
COMMENT=	Verifies the integrity of mp3 audio files

USE_GETOPT_LONG=yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
PLIST_FILES=	bin/mp3_check

.include <bsd.port.mk>
