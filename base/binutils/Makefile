# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.33.1
PORTEPOCH=	0
PORTREVISION=	1
CATEGORIES=	base
MASTER_SITES=	SOURCEWARE/binutils/releases
PKGNAMEPREFIX=	${OPSYS:tl}-
VALID_CATEGORIES=	base

COMMENT=	GNU binary tools for base

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING3.LIB

TARGETARCH=	${ARCH:S/amd64/x86_64/}
BUTARGET=	${TARGETARCH}-unknown-${OPSYS:tl}${OSREL}

USES=		bison:alias cpe gmake libtool tar:bzip2 compiler:env
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/share/info

BUTARGET?=	${PKGNAMEPREFIX}unknown-${OPSYS:tl}${OSREL}
PLIST_SUB=	BUTARGET=${BUTARGET}

TEST_TARGET=	check

PATCHDIR=	${.CURDIR}/../../devel/binutils/files

CONFIGURE_ARGS+=	--disable-host-shared \
			--disable-shared \
			--disable-nls \
			--with-system-zlib \
			--with-sysroot="/" \
			--enable-relro=no \
			--enable-x86-relax-relocations=no \
			--target=${BUTARGET}
PREFIX=	/usr
MAKE_ENV+=	ac_cv_func_sbrk=0
MAKE_ARGS+=	LIBDL=""

BUREMOVE=	addr2line \
		ar \
		c++filt \
		dlltool \
		elfedit \
		gprof \
		objcopy \
		nlmconv \
		nm \
		ranlib \
		readelf \
		size \
		strings \
		strip \
		windmc \
		windres

OPTIONS_DEFINE=	RELRO STATIC 
RELRO_DESC=	enable -z relro in ELF linker by default

RELRO_CONFIGURE_ON=	--enable-relro
RELRO_CONFIGURE_OFF=	--enable-relro=no

STATIC_LDFLAGS+=	-all-static

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif
.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif
.if ${ARCH:Mmips*}
PLIST_SUB+=	MIPS=""
.else
PLIST_SUB+=	MIPS="@comment "
.endif
.if ${ARCH:Mpowerpc*}
PLIST_SUB+=	POWERPC=""
.else
PLIST_SUB+=	POWERPC="@comment "
.endif
.if ${ARCH:Msparc*}
PLIST_SUB+=	SPARC=""
.else
PLIST_SUB+=	SPARC="@comment "
.endif

.if ${HOSTARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-unknown-freebsd${OSREL}
.elif ${HOSTARCH} == "powerpcspe"
CONFIGURE_TARGET=	powerpc-unknown-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${HOSTARCH}-unknown-freebsd${OSREL}
.endif

post-patch:
	${REINPLACE_CMD} -e "s/-ldl//g" ${WRKSRC}/gold/testsuite/Makefile.in

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}
	${RM} ${STAGEDIR}${PREFIX}/${BUTARGET}/lib/ldscripts/i386bsd.*
	@if [ -d ${STAGEDIR}${PREFIX}/${INFO_PATH:H} ] ; then rm -rf ${STAGEDIR}${PREFIX}/${INFO_PATH:H}; fi
	@${RM} -r ${STAGEDIR}${PREFIX}/include
	@${RM} -r ${STAGEDIR}${PREFIX}/lib
.for tool in ${BUREMOVE}
	@${RM} ${STAGEDIR}${PREFIX}/bin/${tool} \
	    ${STAGEDIR}${MANPREFIX}/man/man1/${tool}.1 \
	    ${STAGEDIR}${PREFIX}/${BUTARGET}/bin/${tool}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/toolchains
	${INSTALL_DATA} ${.CURDIR}/files/freebsd-binutils.mk ${STAGEDIR}${PREFIX}/share/toolchains/

.include <bsd.port.post.mk>
