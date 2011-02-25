# ex:ts=8
# Ports collection makefile for:	GDB 7.1
# Date created:				16 November 2010
# Whom:					Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	7.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:S,$,:gdb,}
MASTER_SITE_SUBDIR=gdb/:gdb
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:gdb

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	GNU GDB of newer version than comes with the system

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-system-readline \
		--without-libunwind \
		--enable-target=all \
		--enable-tui
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT
EXCLUDE=	dejagnu expect readline sim texinfo intl
EXTRACT_AFTER_ARGS=| ${TAR} -xf - ${EXCLUDE:S/^/--exclude /}
VER=	${PORTVERSION:S/.//}
PLIST_SUB=	VER=${VER}
MAN1=	gdb${VER}.1

ONLY_FOR_ARCHS=	i386 amd64	# untested elsewhere, might work

OPTIONS=	DEBUG "Build with debugging symbols" off \
		EXPAT "Enable XML parsing for metadata" off \
		PYTHON "Enable Python support" off

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	2.5-2.7
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS+=	-g
.endif

.if defined(WITH_EXPAT)
LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+= --with-expat=yes
.else
CONFIGURE_ARGS+= --without-expat
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+= --with-python=${PYTHON_CMD}
.else
CONFIGURE_ARGS+= --without-python
.endif

# XXX: add OSVERSION check after readline is removed from base
.if exists(${LOCALBASE}/lib/libreadline.so)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
CFLAGS+=	-isystem ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/$$/ [GDB v${PORTVERSION} for FreeBSD]/' \
		${WRKSRC}/gdb/version.in
	@${CP} ${FILESDIR}/fbsd-threads.c ${WRKSRC}/gdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/gdb${VER}
	${LN} ${PREFIX}/bin/gdb${VER} ${PREFIX}/bin/gdbtui${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/gdb.1 ${MAN1PREFIX}/man/man1/gdb${VER}.1

.include <bsd.port.post.mk>
