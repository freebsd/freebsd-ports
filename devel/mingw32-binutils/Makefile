# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	GNU Binutils for Windows cross-development

BINUTILVERSION=	2.23.1

USE_BZIP2=	yes
USES=		gmake iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-win32-registry \
		--disable-shared --disable-werror
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

MAN1=	${PKGNAMEPREFIX}addr2line.1 ${PKGNAMEPREFIX}ar.1    \
	${PKGNAMEPREFIX}as.1 ${PKGNAMEPREFIX}c++filt.1      \
	${PKGNAMEPREFIX}dlltool.1 ${PKGNAMEPREFIX}elfedit.1 \
	${PKGNAMEPREFIX}gprof.1 ${PKGNAMEPREFIX}ld.1        \
	${PKGNAMEPREFIX}nlmconv.1 ${PKGNAMEPREFIX}nm.1      \
	${PKGNAMEPREFIX}objcopy.1 ${PKGNAMEPREFIX}objdump.1 \
	${PKGNAMEPREFIX}ranlib.1 ${PKGNAMEPREFIX}readelf.1  \
	${PKGNAMEPREFIX}size.1 ${PKGNAMEPREFIX}strings.1    \
	${PKGNAMEPREFIX}strip.1 ${PKGNAMEPREFIX}windmc.1    \
	${PKGNAMEPREFIX}windres.1

INFO=		as bfd binutils ld configure gprof standards
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt gprof ld nm objcopy objdump ranlib \
		readelf size strings strip dlltool dllwrap windmc windres

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

#
# UGLY HACK
#
add-plist-post:
	@${ECHO_CMD} "@unexec ${RMDIR} -p %D/${PKGNAMEPREFIX:S/-$//}/info 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} -p %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}
.if (defined(PREFIX) && ${PREFIX} != ${LOCALBASE} && ${PREFIX} != ${LINUXBASE} && ${PREFIX} != "/usr")
	@${ECHO_CMD} "@unexec ${RMDIR} %D 2> /dev/null || true" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif

.include <bsd.port.mk>
