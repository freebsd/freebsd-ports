# New ports collection makefile for:	libiconv
# Date created:				17 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiconv
PORTVERSION=	1.6.1
CATEGORIES=	converters devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.ilog.fr/pub/Users/haible/gnu/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libcharset/configure
CONFIGURE_ARGS=	--enable-static
INSTALLS_SHLIB=	yes

MAN1=		giconv.1
MAN3=		giconv.3 giconv_open.3 giconv_close.3

.include <bsd.port.mk>
