# ex:ts=8
# Ports collection makefile for:	epix
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epix
PORTVERSION=	0.8.7a
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/software/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Creates math plots and line figures using easy-to-learn syntax

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=	epix.1

pre-build:
	@(cd ${WRKSRC} ; ./newbash.sh)

.include <bsd.port.mk>
