# New ports collection makefile for:    unshield
# Date created:         08 April 2004
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	unshield
PORTVERSION=	0.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=synce

MAINTAINER=	se@FreeBSD.org
COMMENT=	Extract data from InstallShield CAB files

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/unshield ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/lib/libunshield.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/lib/.libs/libunshield.a ${PREFIX}/lib
		${INSTALL_DATA} ${WRKSRC}/lib/.libs/libunshield.so.0 ${PREFIX}/lib
		${LN} -sf ${PREFIX}/lib/libunshield.so.0 ${PREFIX}/lib/libunshield.so

.include <bsd.port.mk>
