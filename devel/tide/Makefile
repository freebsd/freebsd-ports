# New ports collection makefile for:	tide
# Date created:				16 October 2000
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	tide
PORTVERSION=	2.0.4
CATEGORIES=	devel
MASTER_SITES=	http://t3x.dyndns.org/files/ \
		http://www.t3x.org/files/
DISTNAME=	tide-${PORTVERSION:S/.//g}

MAINTAINER=	nmh@t3x.org
COMMENT=	T3X Integrated Development Environment and tools

BUILD_DEPENDS=	tx:${PORTSDIR}/lang/t3x
RUN_DEPENDS=	${BUILD_DEPENDS}

ONLY_FOR_ARCHS=	i386

MAKE_ENV+=	T3XDIR=${LOCALBASE}/t3x/r8

do-configure:
	@(cd ${WRKSRC}; make unix)

.include <bsd.port.mk>
