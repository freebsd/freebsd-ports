# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	7.6
#PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	GNU GDB of newer version than comes with the system

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_CSTD=	gnu89
USE_GMAKE=	yes
USES=		iconv
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--with-gdb-datadir=${PREFIX}/share/gdb${PORTVERSION:S/.//g} \
		--with-libiconv-prefix=${LOCALBASE} \
		--without-libunwind-ia64 \
		--enable-targets=all
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT
EXCLUDE=	dejagnu expect sim texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}
VER=	${PORTVERSION:S/.//g}
PLIST_SUB=	VER=${VER}
MAN1=	gdb${VER}.1

ONLY_FOR_ARCHS=	i386 amd64	# untested elsewhere, might work

OPTIONS_DEFINE=	DEBUG EXPAT PYTHON THREADS TUI GDB_LINK
OPTIONS_SINGLE_READLINE=	BASE_READLINE BUNDLED_READLINE PORT_READLINE
OPTIONS_SINGLE=	READLINE
BASE_READLINE_DESC=	from base system(EXPERIMENTAL)
BUNDLED_READLINE_DESC=	from gdb distfile
PORT_READLINE_DESC=	from devel/readline port
GDB_LINK_DESC=	Create the gdb link
TUI_DESC=	Text User Interface enabled
OPTIONS_DEFAULT=	THREADS TUI GDB_LINK PORT_READLINE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDB_LINK}
PLIST_SUB+=	GDB_LINK=""
.else
PLIST_SUB+=	GDB_LINK="@comment "
.endif

.if ${PORT_OPTIONS:MTUI}
CONFIGURE_ARGS+=	--enable-tui
PLIST_SUB+=	TUI_LINK=""
.else
CONFIGURE_ARGS+=	--disable-tui
PLIST_SUB+=	TUI_LINK="@comment "
.endif

.if empty(PORT_OPTIONS:MBUNDLED_READLINE)
EXCLUDE+=	readline
CONFIGURE_ARGS+=	--with-system-readline
.endif

.if ${PORT_OPTIONS:MBASE_READLINE}
CFLAGS+=	-D_rl_echoing_p=readline_echoing_p
USES+=		readline
.endif

.if ${PORT_OPTIONS:MPORT_READLINE}
USES+=		readline:port
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2.5-2.7
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTHREADS}
EXTRA_PATCHES=	${FILESDIR}/extrapatch-gdb-configure.tgt ${FILESDIR}/extrapatch-gdb-Makefile.in
.endif

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-g
.endif

.if ${PORT_OPTIONS:MEXPAT}
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=	--with-expat=yes
.else
CONFIGURE_ARGS+=	--without-expat
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/$$/ [GDB v${PORTVERSION} for FreeBSD]/' \
		${WRKSRC}/gdb/version.in
.if ${PORT_OPTIONS:MTHREADS}
	@${CP} ${FILESDIR}/fbsd-threads.c ${WRKSRC}/gdb/
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/gdb${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/gdb.1 ${MAN1PREFIX}/man/man1/gdb${VER}.1
.if ${PORT_OPTIONS:MTUI}
	${LN} -sf ${PREFIX}/bin/gdb${VER} ${PREFIX}/bin/gdbtui${VER}
.endif
.if ${PORT_OPTIONS:MGDB_LINK}
	${LN} -sf gdb${VER} ${PREFIX}/bin/gdb
.endif
.if ${PORT_OPTIONS:MPYTHON}
	(cd ${WRKSRC}/gdb; ${GMAKE} install-python )
	(cd ${WRKSRC}/gdb/data-directory; ${GMAKE} install-python )
.endif

post-install:
.if ${PORT_OPTIONS:MPYTHON}
	${CHMOD} u+w ${PREFIX}/share/gdb${VER}/python/gdb/*.py*
	${CHMOD} u+w ${PREFIX}/share/gdb${VER}/python/gdb/command/*.py*
.endif

.include <bsd.port.post.mk>
