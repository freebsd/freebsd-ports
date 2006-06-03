# New ports collection makefile for:	tigcc
# Date created:		15 February 2004
# Whom:			Ben Haga <tuximus@tuximus.mine.nu>
#
# $FreeBSD$
#

PORTNAME=	tigcc
PORTVERSION=	0.96.b6
CATEGORIES=	devel
MASTER_SITES=	http://tigcc.ticalc.org/sources/:src \
		http://tigcc.ticalc.org/linux/:linux
DISTNAME=	tigcc_src
DISTFILES=	tigcc_src.tar.bz2:linux gcc-4.0.2.tar.bz2:src gas-2.16.1.tar.bz2:src

MAINTAINER=	walkingshadow@grummel.net
COMMENT=	C compiler for the TI89, 92, and 92+ calculators

BUILD_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog \
		bash:${PORTSDIR}/shells/bash

IS_INTERACTIVE=	yes
USE_BZIP2=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/scripts/Install

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} xjf ${DISTDIR}/tigcc_src.tar.bz2 -C ${WRKSRC}

do-build:
	@${MKDIR} ${WRKSRC}/download
	@${TAR} xjf ${DISTDIR}/gcc-4.0.2.tar.bz2 -C ${WRKSRC}/download
	@${TAR} xjf ${DISTDIR}/gas-2.16.1.tar.bz2 -C ${WRKSRC}/download
	@${LN} -s ${WRKSRC}/download/gcc-4.0.2 ${WRKSRC}/download/gcc.ti
	@${LN} -s ${WRKSRC}/download/binutils-2.16.1 ${WRKSRC}/download/binutils.ti

do-install:
	(cd ${WRKSRC}/scripts; ./Install)

.include <bsd.port.mk>
