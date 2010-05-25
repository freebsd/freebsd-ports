# ex:ts=8
# Ports collection makefile for:	epix
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epix
PORTVERSION=	1.2.7
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/epix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates math plots and line figures using easy-to-learn syntax

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		latex:${PORTSDIR}/print/teTeX

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix="${PREFIX}" --mandir="${PREFIX}/man" \
		--infodir="${PREFIX}/info" --with-bash=${LOCALBASE}/bin/bash

MAN1=		elaps.1 epix.1 flix.1 laps.1
INFO=		epix

.include <bsd.port.mk>
