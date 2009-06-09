# ex:ts=8
# Ports collection makefile for:	epix
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epix
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/epix/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates math plots and line figures using easy-to-learn syntax

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		latex:${PORTSDIR}/print/teTeX

USE_BZIP2=	yes
USE_GCC=	3.4
MAKE_ARGS=	CXX="${CXX}" CFLAGS="${CXXFLAGS} -c" \
		prefix=${PREFIX} \
		INSTALL_PROGRAM="${INSTALL_DATA}" \
		INSTALL_BIN="${INSTALL_SCRIPT}"
PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		epix.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/newbash.sh
	@${REINPLACE_CMD} -e 's|COPYING ||g' ${WRKSRC}/helpfiles.sh

pre-build:
	@(cd ${WRKSRC} ; ./newbash.sh)

.include <bsd.port.mk>
