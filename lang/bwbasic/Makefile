# New ports collection makefile for:	bwbasic
# Date created:		16 Jan 1997
# Whom:			msmith@gsoft.com.au
#
# $FreeBSD$
#

PORTNAME=	bwbasic
PORTVERSION=	2.20
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.rahul.net/pub/rhn/
DISTFILES=	bwbasic-2.20.tar.Z bwb-2.20-patch01.tar.Z.uu.txt

MAINTAINER=	msmith@gsoft.com.au

GNU_CONFIGURE=	yes
EXTRACT_ONLY=	bwbasic-2.20.tar.Z

# The patches come in a totally bizarre format; we have to 
# uudecode them, unpack the resulting tarfile, and then replace
# some of the original files.

pre-patch:
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
	uudecode ${DISTDIR}/bwb-2.20-patch01.tar.Z.uu.txt; \
	tar xzf bwb-2.20-patch01.tar.Z; \
	${MV} bwb-2.20-patch01/* ${WRKSRC}
	${RM} -rf ${WRKSRC}/tmp

# This puts the documentation in ${PREFIX}/share/bwbasic, and the 
# test programs in ${PREFIX}/share/bwbasic/bwbtest.

post-install:
	-${MKDIR} ${PREFIX}/share/bwbasic
	${CP} ${WRKSRC}/bwbasic.doc ${PREFIX}/share/bwbasic/
	${CP} -r ${WRKSRC}/bwbtest ${PREFIX}/share/bwbasic/

.include <bsd.port.mk>
