# New ports collection makefile for:	moxftp
# Date created:		19 December 1994
# Whom:			janek
#
# $FreeBSD$
#

PORTNAME=	moxftp
PORTVERSION=	2.2
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/X11/contrib/applications/ \
		ftp://ftp.inria.fr/X/contrib-R5/applications/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Ftp shell under X Window System

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		${PROGRAM_NAME}.1
PLIST_SUB=	PROGRAM_NAME=${PROGRAM_NAME} RESOURCE_NAME=${RESOURCE_NAME}

.if !defined(WANT_ATHENA_VERSION)
USE_MOTIF=	yes
CONFIGURE_ARGS=	motif
PROGRAM_NAME=	mftp
RESOURCE_NAME=	Mftp
.else
CONFIGURE_ARGS=	athena
PROGRAM_NAME=	xftp
RESOURCE_NAME=	Xftp
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM_NAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PROGRAM_NAME}.man ${MANPREFIX}/man/man1/${PROGRAM_NAME}.1
	${INSTALL_DATA} ${WRKSRC}/${RESOURCE_NAME}.ad ${PREFIX}/lib/X11/app-defaults/${RESOURCE_NAME}

.include <bsd.port.mk>
