# New ports collection makefile for:	kdissert
# Date created:				2004 06 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdissert
PORTVERSION=	0.3.0
CATEGORIES=	deskutils kde
MASTER_SITES=	http://freehackers.org/~tnagy/kdissert/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE mindmapping tool

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
WANT_LIBTOOL_VER=	15
MAKE_ARGS=	CXX="${CXX}" \
		COMMONCXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		LIBTOOL="${LIBTOOL} --silent --tag=CXX" \
		SUBLIBS="${PTHREAD_LIBS}" \
		SHELL="${LOCALBASE}/bin/bash" 
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|!#!${LOCALBASE}/bin/bash|g ; \
		 s|-en|-n|g' ${WRKSRC}/configure

do-configure:
	@cd ${WRKSRC} \
		&& QTDIR="${QT_PREFIX}" ./configure --prefix="${PREFIX}"

.include <bsd.port.mk>
