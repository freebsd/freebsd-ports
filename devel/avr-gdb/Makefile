# Ports collection makefile for:	avr-gdb
# Date created:				3 Sep 2002
# Whom:					Joerg Wunsch <joerg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	6.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gdb
PKGNAMEPREFIX=	avr-
DISTNAME=	gdb-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	GNU GDB for the AVR target

USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=avr --program-prefix=avr --disable-nls

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
