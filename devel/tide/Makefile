# New ports collection makefile for:	tide
# Date created:				16 October 2000
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	tide
PORTVERSION=	3.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.holm-und-jeschag.de/files/
DISTNAME=	tide-${PORTVERSION:S/.//g}

MAINTAINER=	nils@holm-und-jeschag.de
COMMENT=	A collection of classes for the T3X language

BUILD_DEPENDS=	tx:${PORTSDIR}/lang/t3x
RUN_DEPENDS=	${BUILD_DEPENDS}

ONLY_FOR_ARCHS=	i386

MAKE_ENV+=	T3XDIR=${LOCALBASE}/t3x/r8

.include <bsd.port.mk>
