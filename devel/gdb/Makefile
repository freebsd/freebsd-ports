# ex:ts=8
# Ports collection makefile for:	GDB 7.1
# Date created:				16 November 2010
# Whom:					Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	7.1
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
		--without-expat \
		--without-libunwind \
		--without-python \
		--enable-target=all \
		--enable-tui
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-DRL_NO_COMPAT
LDFLAGS+=	-L${LOCALBASE}/lib
EXCLUDE=	dejagnu expect readline sim texinfo intl
EXTRACT_AFTER_ARGS=| ${TAR} -xf - ${EXCLUDE:S/^/--exclude /}
VER=	${PORTVERSION:S/.//}
PLIST_SUB=	VER=${VER}
MAN1=	gdb${VER}.1

ONLY_FOR_ARCHS=	i386 amd64	# untested elsewhere, might work

.include <bsd.port.pre.mk>

# XXX: add OSVERSION check after readline is removed from base
.if exists(${LOCALBASE}/lib/libreadline.so)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
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
