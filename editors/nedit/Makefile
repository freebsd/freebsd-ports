# New ports collection makefile for:	nedit
# Date created:				7 April 1996
# Whom:	Daniel Eischen <deischen@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nedit
PORTVERSION=	5.1.1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nedit.org/pub/v5_1_1/ \
		ftp://ftp.nedit.org/pub/contrib/misc/
DISTFILES=	nedit-5.1.1-src.tar.gz nedit-5.1.app-defaults

MAINTAINER=	deischen@freebsd.org

USE_MOTIF=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
EXTRACT_ONLY=	nedit-5.1.1-src.tar.gz
MAN1=		nclient.1 nedit.1
ALL_TARGET=	freebsd

post-extract:
	${CP} ${DISTDIR}/nedit-5.1.app-defaults ${WRKSRC}/NEdit.ad

.include <bsd.port.mk>
