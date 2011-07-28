# New ports collection makefile for:	msp430mcu
# Date created:		22 June 2011
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	${MCUTARGET}mcu
PORTVERSION=	1.0.${MCUVERSION}
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/mspgcc/${PORTNAME}
DISTNAME=	${PORTNAME}-${MCUVERSION}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Header files for TI's msp430 MCUs cross-development

MCUVERSION=	20110613
MCUTARGET=	msp430

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${MCUVERSION}
PLIST=		${WRKDIR}/.PLIST

MCUINCPATH=	${MCUTARGET}/include
MCULIBPATH=	${MCUTARGET}/lib

pre-install:
	@cd ${WRKSRC} && ${FIND} upstream include -name '*.h' | ${SORT} | ${SED} -E 's,^[^/]+/,${MCUINCPATH}/,' > ${PLIST}
	@${ECHO} ${MCULIBPATH}/msp430mcu.spec >> ${PLIST}
	@cd ${WRKSRC}/analysis/ldscripts && ${FIND} . ! -type d | ${SORT}    | ${SED} 's,^.,${MCULIBPATH}/ldscripts,'         >> ${PLIST}
	@cd ${WRKSRC}/analysis/ldscripts && ${FIND} . -type d ! -name '.' | ${SORT} -r | ${SED} 's,^.,@dirrm ${MCULIBPATH}/ldscripts,'  >> ${PLIST}
	@${ECHO} "@dirrm ${MCUINCPATH}" >> ${PLIST}
	@${ECHO} "@dirrmtry ${MCUINCPATH}" >> ${PLIST}
	@${ECHO} "@dirrmtry ${MCULIBPATH}/ldscripts" >> ${PLIST}
	@${ECHO} "@dirrmtry ${MCULIBPATH}" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && MSP430MCU_ROOT=${WRKSRC} ${SH} scripts/install.sh ${PREFIX}

.include <bsd.port.mk>
