# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	${GDBVERSION}.${PATCHVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		SF/mspgcc/mspgcc:mspgcc
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	msp430-
DISTNAME=	${PORTNAME}-${GDBVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mspgcc-${LTSVERSION}${EXTRACT_SUFX}:mspgcc

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF GDB for TI's msp430 MCUs cross-development

LICENSE=	GPLv3

GDBVERSION=	7.2
LTSVERSION=	20110716
PATCHVERSION=	20110103

WRKSRC=		${WRKDIR}/${PORTNAME}-${GDBVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} --disable-werror --disable-nls
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
MAN1=		${PKGNAMEPREFIX}gdb.1 ${PKGNAMEPREFIX}run.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GDB_TARG=${PKGNAMEPREFIX:S/-$//} \
		GDB_REV=${GDBVERSION}

BINARIES=	gdb:gdb run:sim/msp430
MANPAGES=	gdb.1:gdb run.1:sim/common

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-patch:
	@cd ${WRKSRC} && ${PATCH} -s -p1 < ../mspgcc-${LTSVERSION}/${PKGNAMEPREFIX}${PORTNAME}-${GDBVERSION}-${PATCHVERSION}.patch

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
