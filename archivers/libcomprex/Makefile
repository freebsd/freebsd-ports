# ex:ts=8
# New ports collection makefile for:	libcomprex
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcomprex
PORTVERSION=	0.1.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnupdate

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	bz2:${PORTSDIR}/archivers/bzip2 \
		curl:${PORTSDIR}/ftp/curl

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=	comprex-config.1

.include <bsd.port.mk>
