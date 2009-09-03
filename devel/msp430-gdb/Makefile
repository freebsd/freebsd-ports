# New ports collection makefile for:	msp430-gdb
# Date created:		16 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#
PORTNAME=	gdb
PORTVERSION=	${GDBVERSION}.${PATCHVERSION}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		http://lev.serebryakov.spb.ru/download/msp430/:patches
MASTER_SITE_SUBDIR=	${PORTNAME}/old-releases
PKGNAMEPREFIX=	msp430-
DISTFILES=	${PORTNAME}-${GDBVERSION}${EXTRACT_SUFX} \
		${PKGNAMEPREFIX}${PORTNAME}-${GDBVERSION}.${PATCHVERSION}${EXTRACT_SUFX}:patches

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF gdb-5.1.1 for TI's msp430 MCUs cross-development

BROKEN=		does not support recent versions of FreeBSD

GDBVERSION=	5.1.1
PATCHVERSION=	20030909

WRKSRC=		${WRKDIR}/${PORTNAME}-${GDBVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//}
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
MAN1=		${PKGNAMEPREFIX}gdb.1 ${PKGNAMEPREFIX}run.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GDB_TARG=${PKGNAMEPREFIX:S/-$//} \
		GDB_REV=${GDBVERSION}

BINARIES=	gdb:gdb run:sim/msp430
MANPAGES=	gdb.1:gdb run.1:sim/common

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		Configure fails on amd64 and ia64
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Fails to link
.endif

do-install:
	@${MKDIR} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin
.for F in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${F:C/^.+://}/${F:C/:.+$//} ${PREFIX}/bin/${PKGNAMEPREFIX}${F:C/:.+$//}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}${F:C/:.+$//} \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/${F:C/:.+$//}
.endfor
.for F in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/${F:C/^.+://}/${F:C/:.+$//} ${PREFIX}/man/man${F:C/^.+\.([0-9]).+$/\1/}/${PKGNAMEPREFIX}${F:C/:.+$//}
.endfor
	${INSTALL_DATA} ${WRKSRC}/sim/msp430/libsim.a ${PREFIX}/lib/libmsp430-sim.a

.include <bsd.port.post.mk>
