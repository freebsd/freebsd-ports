# New ports collection makefile for:	moxftp
# Version required:	2.2
# Date created:		19 December 1994
# Whom:			janek
#
# $Id: Makefile,v 1.20 1998/10/13 23:04:41 jseger Exp $
#

DISTNAME=	moxftp-2.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pacbell.com/X11/contrib/applications/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.ORG

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=		${PROGRAM_NAME}.1
PLIST_SUB=	PROGRAM_NAME=${PROGRAM_NAME} RESOURCE_NAME=${RESOURCE_NAME}
STRIP=

# CONFIGURE_ARGS set to :
#	motif - for motif version, (not tested!!!)
#	athena - for athena version,
#	athena3d - for athena 3 d version, (you should have installed Xaw3d!!!)
#	openlook - for open look version - (not tested!!!)
# If you use athena3d uncomment LIB_DEPENDS !!!
.if defined(HAVE_MOTIF)
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
