# ex:ts=8
# Ports collection makefile for:	epix
# Date created:			Sep 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epix
PORTVERSION=	0.8.8a
CATEGORIES=	graphics
MASTER_SITES=	http://mathcs.holycross.edu/~ahwang/software/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_REINPLACE=	yes
MAKE_ARGS=	CXX="${CXX}" CFLAGS="${CXXFLAGS} -c" \
		INSTALL_PROGRAM="${INSTALL_DATA}" \
		INSTALL_BIN="${INSTALL_SCRIPT}"
PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=	epix.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/newbash.sh
	@${REINPLACE_CMD} -e 's|COPYING ||g' ${WRKSRC}/helpfiles.sh

pre-build:
	@(cd ${WRKSRC} ; ./newbash.sh)

.include <bsd.port.mk>
