# New ports collection makefile for:	t3x
# Date created:				15 October 2000
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	t3x
PORTVERSION=	6.10.5
CATEGORIES=	lang devel
MASTER_SITES= 	http://www.not-compatible.org/files/ \
		http://www.t3x.org/files/
DISTNAME=	t3x-6A5

MAINTAINER=	nmh@t3x.org

do-configure:
	@(cd ${WRKSRC}/ports/FreeBSD.elf; ./Config boot)

.include <bsd.port.mk>
