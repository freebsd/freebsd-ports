# New ports collection makefile for:	msp430-libc
# Date created:		15 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	libc
PORTVERSION=	0.1.20021016
CATEGORIES=	devel
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/msp430/
PKGNAMEPREFIX=	msp430-

MAINTAINER=	lev@serebryakov.spb.ru

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}/src

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}

PLIST_SUB+=	LIBC_TARG=${PKGNAMEPREFIX:S/-$//}

post-configure:
	${REINPLACE_CMD} "s|prefix = /usr/local/msp430|prefix = ${PREFIX}|" ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/share/mspgcc
	@tar --exclude CVS -C ${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME} -cf - examples doc | \
		tar -xf - -C ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/share/mspgcc

.include <bsd.port.mk>
