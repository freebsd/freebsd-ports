# New ports collection makefile for:    jikes
# Version required:     0.41
# Date created:         09 December 1998
# Whom:                 Matthew Dillon <dillon@backplane.com>
#
# $Id: Makefile,v 1.8 1999/03/01 01:03:07 archie Exp $
#

DISTNAME=	jikes-0.46
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.whistle.com/pub/archie/misc/

MAINTAINER=	dillon@backplane.com

WRKSRC=		${WRKDIR}/jikes/src
MAN1=		jikes.1
MAKE_ENV=	FILESDIR=${FILESDIR}
PATCH_STRIP=	-p2

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
