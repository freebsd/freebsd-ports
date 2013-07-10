# ex:ts=8
#
# $FreeBSD$
#
# bsd.pure.mk - Support for the Pure language packages
#
# Author: Zhihao Yuan <lichray@gmail.com>
#
# USE_PURE		-	Set it to 'yes' to use libpure.so.
# 					Others are regarded as a list of *RUN_DEPENDS*
# 					to pure-* addons. For example,
# USE_PURE=	ffi 	makes the port depends on pure-ffi at runtime.
# USE_PURE_BUILD	-	Set it to 'yes' to change the addons in USE_PURE
# 						list to *BUILD_DEPENDS*.
# NO_PURE_EXAMPLES	-	Don't automatically install examples/.

.if !defined(PURE_include)

PURE_MAINTAINER=lichray@gmail.com
PURE_include=	bsd.pure.mk

MASTER_SITES?=	http://pure-lang.googlecode.com/files/
DIST_SUBDIR=	pure

USES+=		gmake

_PURE_audio_cat=	audio
_PURE_csv_cat=		textproc
_PURE_ffi_cat=		devel
_PURE_gen_cat=		devel
_PURE_gen_util=		pure-gen
_PURE_gl_cat=		graphics
_PURE_gl_fn=		GL
_PURE_gtk_cat=		x11-toolkits
_PURE_mpfr_cat=		math
_PURE_readline_cat=	devel
_PURE_sockets_cat=	net
_PURE_sql3_cat=		databases
_PURE_tk_cat=		x11-toolkits
_PURE_xml_cat=		textproc

.ifdef _PURE_${PORTNAME}_cat
CATEGORIES=		_PURE_${PORTNAME}_cat
.endif

.if ${PORTNAME} != pure

.if ${USE_PURE} == yes
LIB_DEPENDS+=	pure.8:${PORTSDIR}/lang/pure
.else
. for dep in ${USE_PURE}
_PURE_LIBDIR=	${LOCALBASE}/lib/pure
_PURE_PORTDIR=	${PORTSDIR}/${_PURE_${dep}_cat}/pure-${dep}
.  ifdef _PURE_${dep}_cat
.   ifdef _PURE_${dep}_util
BUILD_DEPENDS+=	${_PURE_${dep}_util}:${_PURE_PORTDIR}
.   else
.    ifdef USE_PURE_BUILD
.     ifdef _PURE_${dep}_fn
BUILD_DEPENDS+=	${_PURE_LIBDIR}/${_PURE_${dep}_fn}.pure:${_PURE_PORTDIR}
.     else
BUILD_DEPENDS+=	${_PURE_LIBDIR}/${dep}.pure:${_PURE_PORTDIR}
.     endif
.    endif
.     ifdef _PURE_${dep}_fn
RUN_DEPENDS+=	${_PURE_LIBDIR}/${_PURE_${dep}_fn}.pure:${_PURE_PORTDIR}
.     else
RUN_DEPENDS+=	${_PURE_LIBDIR}/${dep}.pure:${_PURE_PORTDIR}
.     endif
.   endif
.  else
.   error pure-${dep} is not supported by "bsd.pure.mk"
.  endif
. endfor
.endif

.endif # PORTNAME != pure

MAKE_ARGS+=	prefix=${PREFIX} mandir=${PREFIX}/man \
		CC=${CC} CFLAGS="${CFLAGS}" \
		CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib

.if ${PORTNAME:Mpure-*} !="" && !defined(NO_PURE_EXAMPLES)
PORTEXAMPLES=	*

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.endif

.endif #!defined(PURE_include)
