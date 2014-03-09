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

BINUTILVERSION=	2.24

USE_BZIP2=	yes
USES=		gmake iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-win32-registry \
		--disable-shared --disable-werror
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

INFO=		as bfd binutils ld configure gprof standards
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt gprof ld nm objcopy objdump ranlib \
		readelf size strings strip dlltool dllwrap windmc windres

post-install:
.for F in ${BINARIES}
	@${LN} -f ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

#
# UGLY HACK
#
add-plist-post:
	@${ECHO_CMD} "@unexec ${RMDIR} -p %D/${PKGNAMEPREFIX:S/-$//}/info 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} -p %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}
.if (defined(PREFIX) && defined(LOCALBASE) && defined(LINUXBASE) \
	&& ${PREFIX} != ${LOCALBASE} && ${PREFIX} != ${LINUXBASE} \
	&& ${PREFIX} != "/usr")
	@${ECHO_CMD} "@unexec ${RMDIR} %D 2> /dev/null || true" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif

.include <bsd.port.mk>
