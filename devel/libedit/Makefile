# New ports collection Makefile for:	libedit
# Date created:		9 February 2002
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	libedit
PORTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.canonware.com/download/libedit/

MAINTAINER=	ports@FreeBSD.org

USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--disable-readline
INSTALLS_SHLIB=	yes

MAN3=		editline.3
MAN5=		editrc.5
MLINKS=		editline.3 el_init.3 \
		editline.3 el_end.3 \
		editline.3 el_reset.3 \
		editline.3 el_gets.3 \
		editline.3 el_getc.3 \
		editline.3 el_push.3 \
		editline.3 el_parse.3 \
		editline.3 el_set.3 \
		editline.3 el_get.3 \
		editline.3 el_source.3 \
		editline.3 el_resize.3 \
		editline.3 el_line.3 \
		editline.3 el_insertstr.3 \
		editline.3 el_deletestr.3 \
		editline.3 history_init.3 \
		editline.3 history_end.3 \
		editline.3 history.3
MANCOMPRESSED=	no

.include <bsd.port.mk>
