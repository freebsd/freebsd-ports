# New ports collection makefile for:	moxftp
# Version required:	2.2
# Date created:		19 December 1994
# Whom:			janek
#
# $Id: Makefile,v 1.15 1998/08/05 09:31:35 asami Exp $
#

DISTNAME=	moxftp-2.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pacbell.com/X11/contrib/applications/
EXTRACT_SUFX=	.tar.Z

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
STRIP=
MAN1=		${PROGRAM_NAME}.1

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

#LIB_DEPENDS=	Xaw3d\\.6:${PORTSDIR}/x11-toolkits/Xaw3d

.if !defined (NOMANCOMPRESS)
  GZIP_EXT=.gz
.else
  GZIP_EXT=
.endif

pre-install:
	sed -e 's,@PROGRAM_NAME@,${PROGRAM_NAME},' \
	    -e 's,@RESOURCE_NAME@,${RESOURCE_NAME},' \
	    -e 's,@GZIP_EXT@,${GZIP_EXT},' pkg/PLIST.in >pkg/PLIST

post-install:
	@strip ${PREFIX}/bin/${PROGRAM_NAME}
	@${INSTALL_MAN} ${WRKSRC}/${PROGRAM_NAME}.man ${PREFIX}/man/man1/${PROGRAM_NAME}.1

pre-clean:
	@${RM} -f pkg/PLIST

.include <bsd.port.mk>
