# New ports collection makefile for:	towitoko
# Date created:				Tue Jun 11 20:13:26 CEST 2002
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	towitoko
PORTVERSION=	2.0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/cprados/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UNIX driver for Towitoko smartcard readers

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=	ctapi.3 ctbcs.3
MLINKS=	ctapi.3 CT_close.3 \
	ctapi.3 CT_data.3 \
	ctapi.3 CT_init.3

.include <bsd.port.mk>
