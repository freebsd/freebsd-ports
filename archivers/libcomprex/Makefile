# ex:ts=8
# New ports collection makefile for:	libcomprex
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcomprex
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnupdate

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparently handles automatic compression and decompression of files

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext \
		curl.2:${PORTSDIR}/ftp/curl \
		ltdl.4:${PORTSDIR}/devel/libltdl

.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

GNU_CONFIGURE=	yes
# USE_LIBTOOL=	yes
# LIBTOOLFLAGS=	# none
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lintl"
INSTALLS_SHLIB=	yes

.include "Makefile.man"
.include <bsd.port.mk>
