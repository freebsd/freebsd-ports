# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	7.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	GNU GDB of newer version than comes with the system

LICENSE=	GPLv3

USES=		iconv gmake libtool tar:xz
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--enable-targets=all \
		--with-gdb-datadir=${PREFIX}/share/gdb${PORTVERSION:S/.//g} \
		--with-separate-debug-dir=/usr/lib/debug \
		${ICONV_CONFIGURE_ARG} \
		--without-libunwind-ia64
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT -Wno-unused-function -Wno-unused-variable
EXCLUDE=	dejagnu expect sim texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}

VER=		${PORTVERSION:S/.//g}
PLIST_SUB=	VER=${VER}

ONLY_FOR_ARCHS=	i386 amd64 powerpc powerpc64	# untested elsewhere, might work

OPTIONS_DEFINE=	DEBUG EXPAT GDB_LINK PYTHON THREADS TUI

OPTIONS_DEFAULT=	GDB_LINK THREADS TUI PORT_READLINE

OPTIONS_SINGLE=	READLINE
OPTIONS_SINGLE_READLINE=	BASE_READLINE BUNDLED_READLINE PORT_READLINE

GDB_LINK_DESC=		Create the gdb link
BASE_READLINE_DESC=	from base system(EXPERIMENTAL)
BUNDLED_READLINE_DESC=	from gdb distfile
PORT_READLINE_DESC=	from devel/readline port
TUI_DESC=		Text User Interface enabled

OPTIONS_SUB=	yes

BASE_READLINE_USES=	readline
BASE_READLINE_CFLAGS=	-D_rl_echoing_p=readline_echoing_p
BUNDLED_READLINE_CONFIGURE_OFF=	--with-system-readline
DEBUG_CFLAGS=		-g
EXPAT_CONFIGURE_ON=	--with-expat=yes
EXPAT_CONFIGURE_OFF=	--without-expat
EXPAT_LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_CMD}
PYTHON_CONFIGURE_OFF=	--without-python
PORT_READLINE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-gdb-tui-tui-io.c
PORT_READLINE_USES=	readline:port
TUI_CONFIGURE_ENABLE=	tui

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MBUNDLED_READLINE}
EXCLUDE+=	readline
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2
.endif

.if ${PORT_OPTIONS:MTHREADS}
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-gdb-configure.tgt \
		${FILESDIR}/extrapatch-gdb-Makefile.in
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$| [GDB v${PORTVERSION} for FreeBSD]|' \
		${WRKSRC}/gdb/version.in

.if ${PORT_OPTIONS:MTHREADS}
	@${CP} ${FILESDIR}/fbsd-threads.c ${WRKSRC}/gdb/
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${STAGEDIR}${PREFIX}/bin/gdb${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/doc/gdb.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/gdb${VER}.1

.if ${PORT_OPTIONS:MTUI}
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdbtui${VER}
.endif

.if ${PORT_OPTIONS:MGDB_LINK}
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdb
.endif

.if ${PORT_OPTIONS:MPYTHON}
	(cd ${WRKSRC}/gdb; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
.endif

.if ${PORT_OPTIONS:MPYTHON}
. for f in gdb gdb/command gdb/function
	@(cd ${STAGEDIR}${PREFIX}/share/gdb${VER}/python/${f} ; ${CHMOD} 644 *.py* )
. endfor
.endif

.include <bsd.port.mk>
