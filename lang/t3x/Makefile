# New ports collection makefile for:	t3x
# Date created:				15 October 2000
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	t3x
PORTVERSION=	8.1.5
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://www.holm-und-jeschag.de/files/
DISTNAME=	t3x-${PORTVERSION:S/.//g}

MAINTAINER=	nils@holm-und-jeschag.de
COMMENT=	A compiler for the minimum procedural language T3X

ONLY_FOR_ARCHS=	i386

MAN7=		t3x.7
MANCOMPRESSED=	no

MAKE_ENV+=	INSTALL_PREFIX=${PREFIX}

do-configure:
	@(cd ${WRKSRC}/ports/freebsd-386-elf; ./Config boot)

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} INSTALL_PREFIX=${WRKSRC}/test ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@(cd ${WRKSRC}; ${MAKE} allclean)
	@(cd ${WRKSRC}/ports/freebsd-386-elf; ./Config build)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} T3XDIR=${WRKSRC}/test/t3x/r8 PATH=${PATH}:${WRKSRC}/test/bin ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

.include <bsd.port.mk>
