# New ports collection makefile for:	t3x
# Date created:				15 October 2000
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	t3x
PORTVERSION=	8.0.1
CATEGORIES=	lang devel
MASTER_SITES=	http://t3x.dyndns.org/files/ \
		http://www.t3x.org/files/
DISTNAME=	t3x-${PORTVERSION:S/.//g}

MAINTAINER=	nmh@t3x.org
COMMENT=	A compiler for the minimum procedural language T3X

MAN7=		t3x.7
MANCOMPRESSED=	no

MAKE_ENV=	INSTALL_PREFIX=${PREFIX}

do-configure:
	@(cd ${WRKSRC}/ports/freebsd-386-elf; ./Config boot)

.include <bsd.port.mk>
