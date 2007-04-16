# New ports collection makefile for:	xar
# Date created:		24 January 2005
# Whom:			Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	xar
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.opendarwin.org/projects/xar/ \
		http://distfiles-msn.opendarwin.org/ \
		http://distfiles-od.opendarwin.org/ \
		http://distfiles.opendarwin.org/

MAINTAINER=	CPE1704TKS@bellsouth.net
COMMENT=	OpenDarwin XML eXtensible ARchiver

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

INSTALLS_SHLIB=	yes

USE_GNOME=	libxml2
USE_GMAKE=	yes
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes

MAN1=		xar.1

.include <bsd.port.mk>
