# New ports collection makefile for:	tide
# Date created:				16 October 2000
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	tide
PORTVERSION=	1.6
CATEGORIES=	devel
MASTER_SITES=	http://www.not-compatible.org/files/ \
		http://www.t3x.org/files/
DISTNAME=	tide-${PORTVERSION:S/.//g}

MAINTAINER=	nmh@t3x.org

BUILD_DEPENDS=	tx:${PORTSDIR}/lang/t3x
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_ENV+=	T3XDIR=/usr/local/t3x/r7

do-configure:
	@(cd ${WRKSRC}; ${LN} Makefile.UNX Makefile)
	@(cd ${WRKSRC}/T3Xtools; ${LN} Makefile.UNX Makefile)

.include <bsd.port.mk>
