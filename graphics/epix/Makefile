# ex:ts=8
# Ports collection makefile for:	epix
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epix
PORTVERSION=	0.8.6
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/software/
DISTNAME=	epix_src

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	epix.1

pre-build:
	@(cd ${WRKSRC} ; ./newbash.sh)

.include <bsd.port.mk>
