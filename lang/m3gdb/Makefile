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
MASTER_SITE_SUBDIR=jdp/m3gdb
DISTFILES=	m3gdb-4.17.tar.gz \
		m3gdb-fbsd-4.17.tar.gz

MAINTAINER=	jdp@FreeBSD.org
COMMENT=	The GNU debugger with support for Modula-3

MAN1=		m3gdb.1
MANCOMPRESSED=	yes
ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/m3gdb

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not build"
.endif

.if ${PORTOBJFORMAT} == "aout"
BROKEN=		does not support a.out systems
.endif

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make depend
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make libbuild

.include <bsd.port.post.mk>
