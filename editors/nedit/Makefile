# New ports collection makefile for:	nedit
# Date created:				7 April 1996
# Whom:	Daniel Eischen <deischen@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nedit
PORTVERSION=	5.4
CATEGORIES=	editors
MASTER_SITES=	ftp://nl.nedit.org/pub/NEdit/v5_4/ \
		ftp://nl.nedit.org/pub/NEdit/contrib/misc/ \
		http://nl.nedit.org/ftp/v5_4/ \
		http://nl.nedit.org/ftp/contrib/misc/
DISTFILES=	nedit-5.4-source.tar.bz2 nedit.app-defaults
EXTRACT_ONLY=	nedit-5.4-source.tar.bz2

MAINTAINER=	deischen@freebsd.org
COMMENT=	An X11/Motif GUI text editor for programs and plain text files

USE_BZIP2=	yes
USE_MOTIF=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
MAN1=		nclient.1 nedit.1
ALL_TARGET=	freebsd
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit.ad

.include <bsd.port.mk>
