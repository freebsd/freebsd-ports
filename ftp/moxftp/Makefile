# New ports collection makefile for:	moxftp
# Date created:		19 December 1994
# Whom:			janek
#
# $FreeBSD$
#

PORTNAME=	moxftp
PORTVERSION=	2.2
CATEGORIES=	ftp
MASTER_SITES=	ftp://metalab.unc.edu/pub/X11/contrib/applications/ \
	  	ftp://ftp.inria.fr/X/contrib-R5/applications/ \
		ftp://ftp.tk.mesh.ad.jp/pub/X/contrib/applications/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=		${PROGRAM_NAME}.1
PLIST_SUB=	PROGRAM_NAME=${PROGRAM_NAME} RESOURCE_NAME=${RESOURCE_NAME}
STRIP=

.if !defined(WANT_ATHENA_VERSION)
USE_MOTIF=	yes
CONFIGURE_ARGS=	motif
PROGRAM_NAME=mftp
RESOURCE_NAME=Mftp
.else
CONFIGURE_ARGS=	athena
PROGRAM_NAME=xftp
RESOURCE_NAME=Xftp
.endif

post-install:
	@strip ${PREFIX}/bin/${PROGRAM_NAME}
	@${INSTALL_MAN} ${WRKSRC}/${PROGRAM_NAME}.man ${PREFIX}/man/man1/${PROGRAM_NAME}.1

.include <bsd.port.mk>
