# New ports collection makefile for:	libiconv
# Date created:				17 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiconv
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	converters devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.ilog.fr/pub/Users/haible/gnu/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libcharset/configure
CONFIGURE_ARGS=	--enable-static
INSTALLS_SHLIB=	yes

MAN1=		iconv.1
MAN3=		iconv.3 iconv_open.3 iconv_close.3

pre-build:
	@cd ${WRKSRC} ; /usr/bin/gperf -t -L ANSI-C -H aliases_hash -N aliases_lookup -7 -C -k '1,3-11,$$' -i 1 lib/aliases.gperf > lib/aliases.h

.include <bsd.port.mk>
