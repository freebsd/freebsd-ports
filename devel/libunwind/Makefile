# Created by: stas@FreeBSD.org
# $FreeBSD$

PORTNAME=	libunwind
PORTVERSION=	20121006	# This is actually official libunwind 1.1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH
DISTNAME=	${PORTNAME}-1.1

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Generic stack unwinding library

ONLY_FOR_ARCHS=	i386 amd64

USES=	pkgconfig pathfix
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize libtool
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-c -a
LIBTOOLFILES=	#empty

MAN3=		_U_dyn_cancel.3 \
		_U_dyn_register.3 \
		libunwind.3 \
		libunwind-dynamic.3 \
		libunwind-ia64.3 \
		libunwind-ptrace.3 \
		libunwind-setjmp.3 \
		unw_backtrace.3 \
		unw_create_addr_space.3 \
		unw_destroy_addr_space.3 \
		unw_flush_cache.3 \
		unw_get_accessors.3 \
		unw_get_fpreg.3 \
		unw_get_proc_info.3 \
		unw_get_proc_info_by_ip.3 \
		unw_get_proc_name.3 \
		unw_get_reg.3 \
		unw_getcontext.3 \
		unw_init_local.3 \
		unw_init_remote.3 \
		unw_is_fpreg.3 \
		unw_is_signal_frame.3 \
		unw_regname.3 \
		unw_resume.3 \
		unw_set_caching_policy.3 \
		unw_set_fpreg.3 \
		unw_set_reg.3 \
		unw_step.3 \
		unw_strerror.3

.include <bsd.port.options.mk>

.if ${ARCH} == i386
PLIST_SUB=	ARCH=x86
.elif ${ARCH} == amd64
PLIST_SUB=	ARCH=x86_64
.endif

.include <bsd.port.mk>
