# New ports collection makefile for:	nedit
# Date created:				7 April 1996
# Whom:	Daniel Eischen <deischen@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nedit
PORTVERSION=	5.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nedit.org/pub/v5_2/ \
		ftp://ftp.nedit.org/pub/contrib/misc/
DISTFILES=	nedit-5.2-src.tar.Z nedit.app-defaults

MAINTAINER=	deischen@freebsd.org

USE_MOTIF=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
EXTRACT_ONLY=	nedit-5.2-src.tar.Z
MAN1=		nclient.1 nedit.1
ALL_TARGET=	freebsd

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit.ad

.include <bsd.port.mk>
