# New ports collection makefile for:    jikes
# Version required:     0.41
# Date created:         09 December 1998
# Whom:                 Matthew Dillon <dillon@backplane.com>
#
# UNOFFICIAL PATCH SOURCES:
#	ftp://ftp.crocodile.org/pub/jikes/
#		maintained by Vadim Zaliva
#
# PATCH INFO:	(note: patches had to be regenerated, the patch files in
#		patches/ are not exactly the same as the ftp source)
#
#	patches/patch-aa	
#	    patch to compile under FreeBSD (local)
#
#	patches/patch-ab	
#	    ftp://ftp.crocodile.org/pub/jikes/divide0.patch
#
#	patches/patch-ac
#	    ftp://ftp.crocodile.org/pub/jikes/jikes-0.41-warnings1.patch
#
#	patches/patch-ad
#	    ftp://ftp.crocodile.org/pub/jikes/jikes-array-clone.patch
#
#	(solaris compiler patch not required)
#	    ftp://ftp.crocodile.org/pub/jikes/jikes-solaris2.6-gcc2.8.1.patch
#
#	patches/patch-ae
#	    ftp://ftp.crocodile.org/pub/jikes/jikes.makedepend.patch
#
# $Id: Makefile,v 1.3 1998/12/16 00:12:24 steve Exp $
#

DISTNAME=	jikes-0.41
CATEGORIES=	lang
MASTER_SITES=	http://www.backplane.com/FreeBSDPorts/

MAINTAINER=	dillon@backplane.com

WRKSRC=		${WRKDIR}/jikesos
MAN1=		jikes.1

# 	(sufficiently handled by pkg/MESSAGE, but if IBM has an issue then
#	uncomment this section)
#
#fetch-depends:
#
#.if !defined(READ_IBM_LICENSE)
#	@echo ""
#	@echo "You must read the IBM license prior to using this software,"
#	@echo "then set READ_IBM_LICENSE=YES in /etc/make.conf.local"
#	@echo ""
#	@echo "The license is available at http://www.ibm.com/research/jikes"
#	@false
#.endif

.include <bsd.port.mk>
