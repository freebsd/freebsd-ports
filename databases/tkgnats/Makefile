# New ports collection makefile for:	tkgnats
# Date created:		Sat 18 Apr 1998 10:12:20 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	tkgnats
PORTVERSION=	3.0.16
CATEGORIES=	databases tk82
MASTER_SITES=	http://www.cuug.ab.ca/~macdonal/tkgnats/

MAINTAINER=	jeremy@external.org
COMMENT=	Graphical frontend for the free bug-tracking system

# GNATS archives indicate no support for GNATS 4
DEPRECATED=	Depends on deprecated databases/gnats
EXPIRATION_DATE=2004-08-20

BUILD_DEPENDS=	nedit-pr:${PORTSDIR}/databases/gnats
LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

.include <bsd.port.mk>
