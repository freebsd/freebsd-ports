# New ports collection makefile for:	libiconv
# Date created:				17 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiconv
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	converters devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.ilog.fr/pub/Users/haible/gnu/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
INSTALLS_SHLIB=	yes

MAN1=		iconv.1
MAN3=		iconv.3 iconv_open.3 iconv_close.3

post-install:
	@${LN} -sf ${PREFIX}/bin/iconv ${PREFIX}/bin/giconv
	@${LN} -sf ${PREFIX}/include/iconv.h ${PREFIX}/include/giconv.h
	@${LN} -sf ${PREFIX}/lib/libiconv.a ${PREFIX}/lib/libgiconv.a
	@${LN} -sf ${PREFIX}/lib/libiconv.so ${PREFIX}/lib/libgiconv.so

.include <bsd.port.mk>
