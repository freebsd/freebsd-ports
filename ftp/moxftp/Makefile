# New ports collection makefile for:	moxftp
# Version required:	2.2
# Date created:		19 December 1994
# Whom:			janek
#
# $Id: Makefile,v 1.8 1995/11/27 04:05:17 asami Exp $
#

DISTNAME=	moxftp-2.2
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/
EXTRACT_SUFX=	.tar.Z

HAS_CONFIGURE=	yes
USE_X11=	yes
STRIP=

# CONFIGURE_ARGS set to :
#	motif - for motif version, (not tested!!!)
#	athena - for athena version,
#	athena3d - for athena 3 d version, (you should have installed Xaw3d!!!)
#	openlook - for open look version - (not tested!!!)
# If you use athena3d uncomment DEPENDS !!!
.if defined(HAVE_MOTIF)
CONFIGURE_ARGS=	motif
PROGRAM_NAME=mftp
RESOURCE_NAME=Mftp
.else
CONFIGURE_ARGS=	athena
PROGRAM_NAME=xftp
RESOURCE_NAME=Xftp
.endif

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
	strip ${PREFIX}/bin/${PROGRAM_NAME}
	install -c -m 0444 ${WRKSRC}/${PROGRAM_NAME}.man ${PREFIX}/man/man1/${PROGRAM_NAME}.1
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/${PROGRAM_NAME}.1
.endif

pre-clean:
	@rm -f pkg/PLIST

.include <bsd.port.mk>
