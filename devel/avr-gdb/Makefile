# Ports collection makefile for:	avr-gdb
# Date created:				3 Sep 2002
# Whom:					Joerg Wunsch <joerg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avr-gdb
PORTVERSION=	5.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/releases
DISTNAME=	gdb-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	GNU GDB 5.2.1 for the AVR target

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=avr --program-prefix=avr

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
