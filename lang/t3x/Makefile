# New ports collection makefile for:	t3x
# Date created:				15 October 2000
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	t3x
PORTVERSION=	7.0.3
CATEGORIES=	lang devel
MASTER_SITES= 	http://www.not-compatible.org/files/ \
		http://www.t3x.org/files/
DISTNAME=	t3x-${PORTVERSION:S/.//g}

MAINTAINER=	nmh@t3x.org

do-configure:
	@(cd ${WRKSRC}/ports/freebsd-386-elf; ./Config boot)

.include <bsd.port.mk>
