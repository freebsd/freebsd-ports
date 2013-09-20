# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	${MCUTARGET}mcu
PORTVERSION=	1.0.${MCUVERSION}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/mspgcc/${PORTNAME}
DISTNAME=	${PORTNAME}-${MCUVERSION}

PATCH_SITES=		${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	mspgcc/Patches/LTS/${LTSVERSION}
PATCHFILES=		${LTS_PATCHES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Header files for TI's msp430 MCUs cross-development

LTSVERSION=	20120406
MCUVERSION=	20120406
MCUTARGET=	msp430
BUGS_FIXED=	3522088
LTS_PATCHES!=	for bugid in ${BUGS_FIXED} ; do echo ${PORTNAME}-${MCUVERSION}-sf$${bugid}.patch ; done

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${MCUVERSION}
PLIST=		${WRKDIR}/.PLIST

MCUINCPATH=	${MCUTARGET}/include
MCULIBPATH=	${MCUTARGET}/lib

NO_STAGE=	yes
pre-install:
	@cd ${WRKSRC} && ${FIND} upstream include -name '*.h' | ${SORT} | ${SED} -E 's,^[^/]+/,${MCUINCPATH}/,' > ${PLIST}
	@${ECHO} ${MCULIBPATH}/msp430mcu.spec >> ${PLIST}
	@cd ${WRKSRC}/analysis/ldscripts && ${FIND} . ! -type d | ${SORT}    | ${SED} 's,^.,${MCULIBPATH}/ldscripts,'         >> ${PLIST}
	@cd ${WRKSRC}/analysis/ldscripts && ${FIND} . -type d ! -name '.' | ${SORT} -r | ${SED} 's,^.,@dirrm ${MCULIBPATH}/ldscripts,'  >> ${PLIST}
	@${ECHO} "bin/${PORTNAME}-config" >> ${PLIST}
	@${ECHO} "@dirrm ${MCUINCPATH}" >> ${PLIST}
	@${ECHO} "@dirrmtry ${MCUINCPATH}" >> ${PLIST}
	@${ECHO} "@dirrmtry ${MCULIBPATH}/ldscripts" >> ${PLIST}
	@${ECHO} "@dirrmtry ${MCULIBPATH}" >> ${PLIST}
	@${ECHO} "@dirrmtry ${MCUTARGET}" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && MSP430MCU_ROOT=${WRKSRC} ${SH} scripts/install.sh ${PREFIX}

.include <bsd.port.mk>
