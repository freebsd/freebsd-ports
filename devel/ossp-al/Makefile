# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ossp-al
# Date created:		2003-01-31
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	al
PORTVERSION=	0.9.1
PORTREVISION=	2
PORTEPOCH=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/al/
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Defines an abstract type of buffer that can move data without copying

LIB_DEPENDS=	ex.10:${PORTSDIR}/devel/ossp-ex

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>
