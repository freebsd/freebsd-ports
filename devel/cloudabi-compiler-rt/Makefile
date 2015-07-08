# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiler-rt
DISTVERSION=	0.241676
CATEGORIES=	devel
MASTER_SITES=	https://nuxi.nl/distfiles/compiler-rt/
PKGNAMEPREFIX=	cloudabi-

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Compiler runtime library for CloudABI

LICENSE=	MIT

BUILD_DEPENDS=	x86_64-unknown-cloudabi-ar:${PORTSDIR}/devel/cloudabi-binutils \
		x86_64-unknown-cloudabi-cc:${PORTSDIR}/lang/cloudabi-clang \
		${LOCALBASE}/x86_64-unknown-cloudabi/lib/libc.a:${PORTSDIR}/devel/cloudabi-cloudlibc

USES=		tar:xz

PLIST_FILES=	x86_64-unknown-cloudabi/lib/libcompiler_rt.a

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/lib/builtins

# Do not use the CMake build rules provided by compiler-rt. The CMake build
# rules shipped with compiler-rt depend both on a standard C++ library and a
# compiler that can generate working executables. In our case we are not
# capable of generating executables, for the reason that we need an installed
# copy of compiler-rt.
#
# Fall back to generating the object files and the library manually.
SRCFILES=	absvdi2.c absvsi2.c absvti2.c adddf3.c addsf3.c addtf3.c \
		addvdi3.c addvsi3.c addvti3.c ashldi3.c ashlti3.c ashrdi3.c \
		ashrti3.c clear_cache.c clzdi2.c clzsi2.c clzti2.c cmpdi2.c \
		cmpti2.c comparedf2.c comparesf2.c ctzdi2.c ctzsi2.c ctzti2.c \
		divdc3.c divdf3.c divdi3.c divmoddi4.c divmodsi4.c divsc3.c \
		divsf3.c divsi3.c divtf3.c divti3.c divxc3.c \
		enable_execute_stack.c extendhfsf2.c extendsfdf2.c ffsdi2.c \
		ffsti2.c fixdfdi.c fixdfsi.c fixdfti.c fixsfdi.c fixsfsi.c \
		fixsfti.c fixunsdfdi.c fixunsdfsi.c fixunsdfti.c fixunssfdi.c \
		fixunssfsi.c fixunssfti.c fixunsxfdi.c fixunsxfsi.c \
		fixunsxfti.c fixxfdi.c fixxfti.c floatsidf.c floatsisf.c \
		floattidf.c floattisf.c floattixf.c floatunsidf.c \
		floatunsisf.c floatuntidf.c floatuntisf.c floatuntixf.c \
		int_util.c lshrdi3.c lshrti3.c moddi3.c modsi3.c modti3.c \
		muldc3.c muldf3.c muldi3.c mulodi4.c mulosi4.c muloti4.c \
		mulsc3.c mulsf3.c multf3.c multi3.c mulvdi3.c mulvsi3.c \
		mulvti3.c mulxc3.c negdf2.c negdi2.c negsf2.c negti2.c \
		negvdi2.c negvsi2.c negvti2.c paritydi2.c paritysi2.c \
		parityti2.c popcountdi2.c popcountsi2.c popcountti2.c \
		powidf2.c powisf2.c powitf2.c powixf2.c subdf3.c subsf3.c \
		subtf3.c subvdi3.c subvsi3.c subvti3.c trampoline_setup.c \
		truncdfhf2.c truncdfsf2.c truncsfhf2.c ucmpdi2.c ucmpti2.c \
		udivdi3.c udivmoddi4.c udivmodsi4.c udivmodti4.c udivsi3.c \
		udivti3.c umoddi3.c umodsi3.c umodti3.c x86_64/floatdidf.c \
		x86_64/floatdisf.c x86_64/floatdixf.c x86_64/floatundidf.S \
		x86_64/floatundisf.S x86_64/floatundixf.S

do-build:
.for f in ${SRCFILES}
	${LOCALBASE}/bin/x86_64-unknown-cloudabi-cc -O2 \
		-c -o ${WRKSRC}/$f.o ${WRKSRC}/$f
.endfor
	cd ${WRKSRC}; ${LOCALBASE}/bin/x86_64-unknown-cloudabi-ar -rcs \
		libcompiler_rt.a ${SRCFILES:S/$/.o/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/
	${INSTALL_DATA} ${WRKSRC}/libcompiler_rt.a \
		${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi/lib/

.include <bsd.port.mk>
