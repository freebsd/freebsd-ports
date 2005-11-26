# New ports collection makefile for:   m3gdb
# Date created:        17 February 1999
# Whom:                wagner@luthien.in-berlin.de
#
# $FreeBSD$
#

PORTNAME=	m3gdb
PORTVERSION=	4.17
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jdp/${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-fbsd-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU debugger with support for Modula-3

DEPRECATED=	does not build on recent releases
EXPIRATION_DATE=	2006-01-26

MAN1=		m3gdb.1
MANCOMPRESSED=	yes
ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/m3gdb

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 503000
BROKEN=		"Does not build on FreeBSD >= 5.x"
.endif

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} depend
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} libbuild

.include <bsd.port.post.mk>
