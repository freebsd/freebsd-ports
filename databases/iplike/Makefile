# New ports collection makefile for:	iplike
# Date created:		5 January 2010
# Whom:			Sevan Janiyan <venture37@geeklan.co.uk>
#
# $FreeBSD$
#

PORTNAME=	iplike
PORTVERSION=	1.0.9
CATEGORIES=	databases
MASTER_SITES=	SF/opennms/IPLIKE/stable-1.0/

MAINTAINER=	venture37@geeklan.co.uk
COMMENT=	C implementation of the OpenNMS iplike stored procedure

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PGSQL=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	lib/iplike.la \
	lib/iplike.so \
	sbin/install_iplike.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
