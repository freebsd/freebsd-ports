# New ports collection makefile for:    jikes
# Date created:         09 December 1998
# Whom:                 Matthew Dillon <dillon@backplane.com>
#
# $FreeBSD$
#

PORTNAME=	jikes
PORTVERSION=	1.11
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.whistle.com/pub/archie/misc/

MAINTAINER=	archie@whistle.com

WRKSRC=		${WRKDIR}/jikes/src
MAN1=		jikes.1
MAKE_ENV=	WRKDIR=${WRKDIR}
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
#	@${FALSE}
#.endif

.include <bsd.port.mk>
