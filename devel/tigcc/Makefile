# New ports collection makefile for:	tigcc
# Date created:		15 February 2004
# Whom:			Ben Haga <tuximus@tuximus.mine.nu>
#
# $FreeBSD$
#

PORTNAME=	tigcc
PORTVERSION=	0.95
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://tigcc.ticalc.org/sources/\
		http://tigcc.ticalc.org/linux/
DISTNAME=	tigcc_src
DISTFILES=	tigcc_src.tar.bz2 gcc-3.3.3.tar.bz2 gas-2.14.tar.bz2

MAINTAINER=	tuximus@tuximus.mine.nu
COMMENT=	C compiler for the TI89, 92, and 92+ calculators

BUILD_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog \
		bash:${PORTSDIR}/shells/bash2

IS_INTERACTIVE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/scripts/Install

do-build:
	(cd ${WRKSRC}/; \
	${MKDIR} download; \
	${CP} ${DISTDIR}/gcc-3.3.3.tar.bz2 ${DISTDIR}/gas-2.14.tar.bz2 download; \
	cd download; \
	${TAR} yxf gas-2.14.tar.bz2; \
	${TAR} yxf gcc-3.3.3.tar.bz2; \
	${LN} -s binutils-2.14 binutils.ti)

do-install:
	(cd ${WRKSRC}/scripts; ./Install)

.include <bsd.port.mk>
