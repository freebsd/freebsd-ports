# Ports collection makefile for:	GDB
# Date created:				16 November 2010
# Whom:					Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	7.4.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	GNU GDB of newer version than comes with the system

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--with-gdb-datadir=${PREFIX}/share/gdb${PORTVERSION:S/.//g} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-system-readline \
		--without-libunwind \
		--enable-target=all \
		--enable-tui
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT
EXCLUDE=	dejagnu expect readline sim texinfo intl
EXTRACT_AFTER_ARGS=| ${TAR} -xf - ${EXCLUDE:S/^/--exclude /}
VER=	${PORTVERSION:S/.//g}
PLIST_SUB=	VER=${VER}
MAN1=	gdb${VER}.1

ONLY_FOR_ARCHS=	i386 amd64	# untested elsewhere, might work

# Forcing to use readline.6 from ports (newer readline in FreeBSD world is not
# compatible anymore). Please ignore portlint here.
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
CFLAGS+=	-isystem ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG EXPAT PYTHON THREADS GDB_LINK
GDB_LINK_DESC=	Create the gdb link
OPTIONS_DEFAULT=	THREADS GDB_LINK

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDB_LINK}
PLIST_SUB+=	GDB_LINK=""
.else
PLIST_SUB+=	GDB_LINK="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2.5-2.7
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

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		PYTHON="@comment "
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
	@${CP} ${FILESDIR}/amd64bsd-nat.h ${WRKSRC}/gdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/gdb${VER}
	${LN} ${PREFIX}/bin/gdb${VER} ${PREFIX}/bin/gdbtui${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/gdb.1 ${MAN1PREFIX}/man/man1/gdb${VER}.1
.if ${PORT_OPTIONS:MGDB_LINK}
	${LN} -sf gdb${VER} ${PREFIX}/bin/gdb
.endif
.if ${PORT_OPTIONS:MPYTHON}
	(cd ${WRKSRC}/gdb; ${GMAKE} install-python )
	(cd ${WRKSRC}/gdb/data-directory; ${GMAKE} install-python )
.endif

.include <bsd.port.post.mk>
