# New ports collection makefile for:	libffi
# Date created:			14, June, 1998
# Whom:				Horance Chou <horance@freedom.ie.cycu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	libffi
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/libffi/

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Foreign Function Interface

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake:110 autoconf:261

INFO=		libffi

MAN3=		ffi.3 ffi_call.3 ffi_prep_cif.3

pre-configure:
		@${REINPLACE_CMD} -e 's,^\(includesdir = \).*,\1$$(includedir),' \
			${WRKSRC}/include/Makefile.am

post-configure:
		@${REINPLACE_CMD} -e 's,^\(transform = \).*,\1,' \
			${WRKSRC}/man/Makefile

.include <bsd.port.mk>
