# New ports collection makefile for:	xar
# Date created:		24 January 2005
# Whom:			Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	xar
DISTVERSION=	1.5.1
CATEGORIES=	archivers
MASTER_SITES=	http://xar.googlecode.com/files/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	CPE1704TKS@bellsouth.net
COMMENT=	OpenDarwin XML eXtensible ARchiver

USE_LDCONFIG=	yes

USE_GNOME=	libxml2
USE_GMAKE=	yes
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes

MAN1=		xar.1

.include <bsd.port.mk>
