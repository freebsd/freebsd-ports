# New ports collection makefile for:	nedit
# Date created:				7 April 1996
# Whom:	Daniel Eischen <deischen@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nedit
PORTVERSION=	5.5
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nedit.org/pub/NEdit/v5_5/ \
		ftp://ftp.nedit.org/pub/NEdit/contrib/misc/ \
		http://www.nedit.org/ftp/v5_5/ \
		http://www.nedit.org/ftp/contrib/misc/
DISTFILES=	nedit-5.5-src.tar.bz2 nedit.app-defaults
EXTRACT_ONLY=	nedit-5.5-src.tar.bz2

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
