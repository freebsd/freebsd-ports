# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gauche
PORTVERSION=	0.9.3.3
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	SF/${PORTNAME}/Gauche/
DISTNAME=	Gauche-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@elfga.com
COMMENT=	Scheme script interpreter with multibyte character handling

OPTIONS_DEFINE=	GDBM SLIB DOCS MANPAGES
OPTIONS_SINGLE=	THREADS MULTIBYTE
OPTIONS_SINGLE_THREADS=	PTHREADS NO_THREADS
OPTIONS_SINGLE_MULTIBYTE=UTF8 EUCJP SJIS NO_MULTIBYTE
OPTIONS_DEFAULT=PTHREADS UTF8 MANPAGES
SLIB_DESC=	Create catalogue for SLIB port
PTHREADS_DESC=	Enable POSIX thread support
NO_THREADS_DESC=No threading support
EUCJP_DESC=	EUC-JP encoding support
SJIS_DESC=	Shift_JIS encoding support
NO_MULTIBYTE_DESC=No multibyte character encoding support
NO_OPTIONS_SORT=yes

# breaks in ext/uvecor.c on some locales
MAKE_ENV=	LANG=C
# avoids a problem with with ccache's pre-processor optimization
MAKE_ENV+=	CCACHE_CPP2=1

DATADIR?=	${PREFIX}/share/${PORTNAME}-0.9

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tls=none \
		--with-iconv=${ICONV_PREFIX}
PLIST_SUB=	VERSION="${PORTVERSION}" \
		TARGET="${CONFIGURE_TARGET}"
USES=		iconv
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INFO=		gauche-refe gauche-refj
.endif

.if ${PORT_OPTIONS:MMANPAGES}

MAN1=		gosh.1 gauche-cesconv.1 gauche-config.1 gauche-install.1 \
		gauche-package.1

.else
MANPREFIX=	${WRKDIR}
.endif

.if ${PORT_OPTIONS:MGDBM}
CONFIGURE_ARGS+=--with-local=${LOCALBASE}
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
PLIST_SUB+=	GDBM=""
.else
PLIST_SUB+=	GDBM="@comment "
.endif

.if ${PORT_OPTIONS:MSLIB}
BUILD_DEPENDS+=	slib>=0:${PORTSDIR}/lang/slib
CONFIGURE_ARGS+=--with-slib=${LOCALBASE}/share/slib
PLIST_SUB+=	SLIB=""
.else
CONFIGURE_ARGS+=--with-slib=${WRKDIR}
PLIST_SUB+=	SLIB="@comment "
.endif

.if ${PORT_OPTIONS:MPTHREADS}
CONFIGURE_ARGS+=	--enable-threads=pthreads
.else
CONFIGURE_ARGS+=	--enable-threads=no
.endif

.if ${PORT_OPTIONS:MUTF8}
CONFIGURE_ARGS+=	--enable-multibyte=utf-8
.elif ${PORT_OPTIONS:MEUCJP}
CONFIGURE_ARGS+=	--enable-multibyte=euc-jp
.elif ${PORT_OPTIONS:MSJIS}
CONFIGURE_ARGS+=	--enable-multibyte=sjis
.else
CONFIGURE_ARGS+=	--enable-multibyte=none
.endif

.include <bsd.port.pre.mk>

NOT_FOR_ARCHS=		ia64 powerpc sparc64
NOT_FOR_ARCHS_REASON=	Does not compile on ia64, powerpc, or sparc64

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|all: info|all:|' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gosh
	${MKDIR} ${PREFIX}/share/gauche/site/lib/.packages
	${TOUCH} ${PREFIX}/share/gauche/site/lib/.packages/.keepme
	${TOUCH} ${PREFIX}/lib/gauche-0.9/site/${CONFIGURE_TARGET}/.keepme
	${MKDIR} ${PREFIX}/share/gauche/${PORTVERSION}/lib/.packages
	${TOUCH} ${PREFIX}/share/gauche/${PORTVERSION}/lib/.packages/.keepme
	${MKDIR} ${DOCSDIR}
	${TOUCH} ${DOCSDIR}/.keepme
	${MKDIR} ${EXAMPLESDIR}
	${TOUCH} ${EXAMPLESDIR}/.keepme
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/*.info.gz ${WRKSRC}/doc/*.info-[1-7].gz ${PREFIX}/info/
.endif

regression-test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.post.mk>
