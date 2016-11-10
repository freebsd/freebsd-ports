# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gauche
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	SF/${PORTNAME}/Gauche
DISTNAME=	Gauche-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scheme script interpreter with multibyte character handling

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	Fails to link: missing sbrk
BROKEN_armv6=	Fails to build: unknown attribute __alloc_size__; also fails in assembler
BROKEN_mips=	Fails to build: redefinition of GC_register_dynamic_libraries
BROKEN_mips64=	Fails to build: redefinition of GC_register_dynamic_libraries
BROKEN_sparc64=	Fails to build: do not know how to make sparc_mach_dep.lo

USES=		iconv makeinfo tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tls=none \
		${ICONV_CONFIGURE_BASE:S/lib//}
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

PLIST_SUB=	VERSION="${PORTVERSION}" \
		TARGET="${CONFIGURE_TARGET}"

# breaks in ext/uvecor.c on some locales
MAKE_ENV+=	LANG=C
# avoids a problem with with ccache's pre-processor optimization
MAKE_ENV+=	CCACHE_CPP2=1

INFO=		gauche-refe gauche-refj

OPTIONS_DEFINE=		GDBM THREADS SLIB
OPTIONS_RADIO=		MULTIBYTE
OPTIONS_RADIO_MULTIBYTE=	EUCJP SJIS UTF8
OPTIONS_DEFAULT=	THREADS UTF8
OPTIONS_SUB=		yes

EUCJP_DESC=		EUC-JP encoding support
EUCJP_CONFIGURE_ON=	--enable-multibyte=euc-jp
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_ON=	--with-local=${LOCALBASE}
SLIB_DESC=		Create catalogue for SLIB port
SLIB_BUILD_DEPENDS=	slib>0:lang/slib
SLIB_CONFIGURE_ON=	--with-slib=${LOCALBASE}/share/slib
SLIB_CONFIGURE_OFF=	--with-slib=${WRKDIR}
SJIS_DESC=		Shift_JIS encoding support
SJIS_CONFIGURE_ON=	--enable-multibyte=sjis
THREADS_CONFIGURE_ON=	--enable-threads=pthreads
THREADS_CONFIGURE_OFF=	--enable-threads=no
UTF8_CONFIGURE_ON=	--enable-multibyte=utf-8

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MEUCJP} && !${PORT_OPTIONS:MSJIS} && !${PORT_OPTIONS:MUTF8}
CONFIGURE_ARGS+=	--enable-multibyte=none
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/configure

post-install:
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/gauche-0.9/site/${CONFIGURE_TARGET}/.keepme
	@${MKDIR} ${STAGEDIR}${DATADIR}/${PORTVERSION}/lib/.packages
	@${TOUCH} ${STAGEDIR}${DATADIR}/${PORTVERSION}/lib/.packages/.keepme
	@${MKDIR} ${STAGEDIR}${DATADIR}/site/lib/.packages
	@${TOUCH} ${STAGEDIR}${DATADIR}/site/lib/.packages/.keepme
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gauche-0.9/site/lib/.packages
	@${TOUCH} ${STAGEDIR}${PREFIX}/share/gauche-0.9/site/lib/.packages/.keepme
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${TOUCH} ${STAGEDIR}${DOCSDIR}/.keepme
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TOUCH} ${STAGEDIR}${EXAMPLESDIR}/.keepme
.for i in gauche-config gosh
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/${i}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
	@${CHMOD} u-w ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgauche-0.9.so.[0-9].*
.for i in gauche-config gosh *.so
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/gauche-0.9/${PORTVERSION}/${CONFIGURE_TARGET}/${i}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gauche-0.9/${PORTVERSION}/${CONFIGURE_TARGET}/${i}
	@${CHMOD} u-w ${STAGEDIR}${PREFIX}/lib/gauche-0.9/${PORTVERSION}/${CONFIGURE_TARGET}/${i}
.endfor

regression-test: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
