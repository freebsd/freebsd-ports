# New ports collection Makefile for:	libstash
# Date created:		22 August 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	libstash
PORTVERSION=	1.2.0
CATEGORIES=	devel
DISTNAME=	canonware-1.2.0
MASTER_SITES=	http://www.canonware.com/download/canonware/

MAINTAINER=	jasone@FreeBSD.org

BUILD_DEPENDS=	cook:${PORTSDIR}/devel/cook

GNU_CONFIGURE=	yes

MAN3= libstash_dbg.3s libstash_pezz.3s libstash_rwl.3s \
	libstash.3s libstash_dch.3s libstash_pool.3s libstash_sema.3s \
	libstash_bhp.3s libstash_mem.3s libstash_ql.3s libstash_thd.3s \
	libstash_buf.3s libstash_mq.3s libstash_qr.3s libstash_treen.3s \
	libstash_ch.3s libstash_mtx.3s libstash_qs.3s libstash_tsd.3s \
	libstash_cnd.3s libstash_out.3s libstash_res.3s libstash_xep.3s
MANCOMPRESSED=	no

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook libstash)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook libstash_install)

.include <bsd.port.mk>
