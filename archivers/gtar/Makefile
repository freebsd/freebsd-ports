# New ports collection makefile for:	gtar
# Date created:		Sa   6 Jun 1998 10:24:51 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	tar
PORTVERSION=	1.13.25
PORTREVISION=	8
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	g

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GNU version of the traditional tar archiver

INFO=		tar

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		LDFLAGS='-L${LOCALBASE}/lib ${LDSTATIC}' \
		DEFAULT_ARCHIVE='/dev/sa0' \
		MAKEINFO='makeinfo --no-split' \
		am_cv_func_iconv=no

.if defined(WANT_STATIC)
LDSTATIC=	-static
.else
LDSTATIC=
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 470000
IGNORE=		is in the base system
.endif

.include <bsd.port.post.mk>
