# ex:ts=8
# Ports collection makefile for:	rexx-curl
# Date created:			Nov 11, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rexx${PORTNAME}
PKGNAMEPREFIX=	rexx-
DISTNAME=	RexxCURL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An external function package providing an interface to the cURL package

BUILD_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina
LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rexx=regina
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
DATADIR=	${PREFIX}/share/rexx${PORTNAME}

.include <bsd.port.mk>
