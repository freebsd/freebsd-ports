# New ports collection makefile for:	artsrapper
# Date created:				2004-03-04
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	artswrapper
PORTVERSION=	1.2.1
CATEGORIES=	audio
DISTNAME=	# none
EXTRACT_SUFX=	# none

MAINTAINER=	kde@freebsd.org
COMMENT=	Setuid wrapper for arts

IGNORE=		This port is part of KDE 3.2.1 and is not yet ready

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/artswrapper

do-fetch:

.include <bsd.port.pre.mk>

do-build:
	${CC} ${CFLAGS} -DHAVE_REALTIME_SCHED -DEXECUTE=\"${LOCALBASE}/bin/artsd\" -o ${WRKSRC}/artswrapper ${FILESDIR}/artswrapper.c

do-install:
	${INSTALL} ${COPY} ${STRIP} ${_BINOWNGRP} -m 4555 ${WRKSRC}/artswrapper ${PREFIX}/bin

.include <bsd.port.post.mk>
