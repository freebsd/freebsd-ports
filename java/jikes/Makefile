# New ports collection makefile for:    jikes
# Version required:     0.41
# Date created:         09 December 1998
# Whom:                 Matthew Dillon <dillon@backplane.com>
#
# $Id: Makefile,v 1.7 1998/12/23 13:13:21 asami Exp $
#

DISTNAME=	jikes-0.45
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.whistle.com/pub/archie/misc/

MAINTAINER=	dillon@backplane.com

WRKSRC=		${WRKDIR}/jikes
MAN1=		jikes.1
MAKE_ENV=	FILESDIR=${FILESDIR}
SCRIPTS_ENV=	FILESDIR=${FILESDIR} PKGDIR=${PKGDIR}
PATCH_STRIP=	-p1

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
