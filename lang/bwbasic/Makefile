# New ports collection makefile for:	bwbasic
# Version required:	2.20
# Date created:		16 Jan 1997
# Whom:			msmith@gsoft.com.au
#
# $Id: Makefile,v 1.5 1996/12/31 08:25:17 msmith Exp $
#

DISTNAME=	bwbasic-2.20
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.rahul.net/pub/rhn/
DISTFILES=	bwbasic-2.20.tar.Z bwb-2.20-patch01.tar.Z.uu.txt
EXTRACT_ONLY=	bwbasic-2.20.tar.Z

MAINTAINER=	msmith@gsoft.com.au

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

# The patches come in a totally bizarre format; we have to 
# uudecode them, unpack the resulting tarfile, and then replace
# some of the original files.
#
# This method pollutes the port directory temporarily. 

pre-patch:
	uudecode ${DISTDIR}/bwb-2.20-patch01.tar.Z.uu.txt
	tar xzf bwb-2.20-patch01.tar.Z
	mv bwb-2.20-patch01/* ${WRKSRC}
	rm -rf bwb-2.20-patch01 bwb-2.20-patch01.tar.Z

# This puts the documentation in ${PREFIX}/share/bwbasic, and the 
# test programs in ${PREFIX}/share/bwbasic/bwbtest.

post-install:
	-${MKDIR} ${PREFIX}/share/bwbasic
	${CP} ${WRKSRC}/bwbasic.doc ${PREFIX}/share/bwbasic/
	${CP} -r ${WRKSRC}/bwbtest ${PREFIX}/share/bwbasic/

.include <bsd.port.mk>
