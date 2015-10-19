# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	${GDBVERSION}.${PATCHVERSION}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU SF/mspgcc/mspgcc:mspgcc
PKGNAMEPREFIX=	msp430-
DISTNAME=	${PORTNAME}-${GDBVERSION}a
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mspgcc-${LTSVERSION}${EXTRACT_SUFX}:mspgcc

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF GDB for TI's msp430 MCUs cross-development

LICENSE=	GPLv3

DEPRECATED=		Obsolete. Please, use devel/gcc-msp430-ti-toolchain
EXPIRATION_DATE=	2016-01-08

GDBVERSION=	7.2
LTSVERSION=	20110716
PATCHVERSION=	20110103

WRKSRC=		${WRKDIR}/${PORTNAME}-${GDBVERSION}

USES=		tar:bzip2 gmake iconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-libiconv-prefix=${LOCALBASE} \
		--disable-werror \
		--disable-nls
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GDB_TARG=${PKGNAMEPREFIX:S/-$//} \
		GDB_REV=${GDBVERSION}

BINARIES=	gdb:gdb run:sim/msp430
MANPAGES=	gdb.1:gdb run.1:sim/common

.include <bsd.port.pre.mk>

pre-patch:
	@cd ${WRKSRC} && ${PATCH} -s -p1 < ../mspgcc-${LTSVERSION}/${PKGNAMEPREFIX}${PORTNAME}-${GDBVERSION}-${PATCHVERSION}.patch

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin
.for F in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${F:C/^.+://}/${F:C/:.+$//} ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${F:C/:.+$//}
	@${LN} -f ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${F:C/:.+$//} \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/${F:C/:.+$//}
.endfor
.for F in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/${F:C/^.+://}/${F:C/:.+$//} ${STAGEDIR}${PREFIX}/man/man${F:C/^.+\.([0-9]).+$/\1/}/${PKGNAMEPREFIX}${F:C/:.+$//}
.endfor
	${INSTALL_DATA} ${WRKSRC}/sim/msp430/libsim.a ${STAGEDIR}${PREFIX}/lib/libmsp430-sim.a

.include <bsd.port.post.mk>
