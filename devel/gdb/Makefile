# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	7.6.1
#PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	GNU GDB of newer version than comes with the system

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_CSTD=	gnu89
USES=		iconv gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--with-gdb-datadir=${STAGEDIR}${PREFIX}/share/gdb${PORTVERSION:S/.//g} \
		${ICONV_CONFIGURE_ARG} \
		--without-libunwind-ia64 \
		--enable-targets=all
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT
EXCLUDE=	dejagnu expect sim texinfo intl
VER=		${PORTVERSION:S/.//g}
PLIST_SUB=	VER=${VER}
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}

ONLY_FOR_ARCHS=	i386 amd64 powerpc powerpc64	# untested elsewhere, might work

OPTIONS_DEFINE=	DEBUG EXPAT PYTHON THREADS TUI GDB_LINK
OPTIONS_SINGLE_READLINE=	BASE_READLINE BUNDLED_READLINE PORT_READLINE
OPTIONS_SINGLE=	READLINE
BASE_READLINE_DESC=	from base system(EXPERIMENTAL)
BUNDLED_READLINE_DESC=	from gdb distfile
PORT_READLINE_DESC=	from devel/readline port
GDB_LINK_DESC=		Create the gdb link
TUI_DESC=		Text User Interface enabled
OPTIONS_DEFAULT=	THREADS TUI GDB_LINK PORT_READLINE

# Activating the plist
OPTIONS_SUB=yes

DEBUG_CFLAGS=		-g
EXPAT_CONFIGURE_ON=	--with-expat=yes
EXPAT_CONFIGURE_OFF=	--without-expat
EXPAT_LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2
TUI_CONFIGURE_ENABLE=	tui
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_CMD}
PYTHON_CONFIGURE_OFF=	--without-python
PORT_READLINE_USES=	readline:port
BASE_READLINE_USES=	readline
BASE_READLINE_CFLAGS=	-D_rl_echoing_p=readline_echoing_p
BUNDLED_READLINE_CONFIGURE_OFF=	--with-system-readline

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MBUNDLED_READLINE)
EXCLUDE+=	readline
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2.5-2.7
.endif

.if ${PORT_OPTIONS:MTHREADS}
EXTRA_PATCHES=	${FILESDIR}/extrapatch-gdb-configure.tgt ${FILESDIR}/extrapatch-gdb-Makefile.in
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
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${STAGEDIR}${PREFIX}/bin/gdb${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/gdb.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/gdb${VER}.1
.if ${PORT_OPTIONS:MTUI}
	${LN} -sf ${STAGEDIR}${PREFIX}/bin/gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdbtui${VER}
.endif
.if ${PORT_OPTIONS:MGDB_LINK}
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdb
.endif
.if ${PORT_OPTIONS:MPYTHON}
	(cd ${WRKSRC}/gdb; ${GMAKE} install-python )
	(cd ${WRKSRC}/gdb/data-directory; ${GMAKE} install-python )
.endif

post-install:
.if ${PORT_OPTIONS:MPYTHON}
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/share/gdb${VER}/python/gdb/*.py*
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/share/gdb${VER}/python/gdb/command/*.py*
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/share/gdb${VER}/python/gdb/function/*.py*
.endif

.include <bsd.port.mk>
