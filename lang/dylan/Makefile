# New ports collection makefile for:    Dylan
# Date created:         23 Jan 1998
# Whom:                 housel@acm.org
#
# $FreeBSD$
#

PORTNAME=	dylan
PORTVERSION=	2.4.0
CATEGORIES=	lang
MASTER_SITES=	http://www.gwydiondylan.org/downloads/src/tar/         \
		http://www.gwydiondylan.org/downloads/binaries/FreeBSD/x86/ \
		ftp://ftp.gwydiondylan.org/downloads/src/tar/         \
		ftp://ftp.gwydiondylan.org/downloads/binaries/FreeBSD/x86/ \
		ftp://ftp.ntua.gr/pub/lang/gwydion/src/tar/            \
		ftp://ftp.ntua.gr/pub/lang/gwydion/binaries/FreeBSD/x86/ \
		ftp://ftp.fu-berlin.de/pub/unix/languages/dylan/src/tar/   \
		ftp://ftp.fu-berlin.de/pub/unix/languages/dylan/binaries/FreeBSD/x86/
DISTNAME=	gwydion-dylan-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} d2c-${PORTVERSION}-FreeBSD.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	housel@acm.org
COMMENT=	CMU Gwydion project interpreter and compiler for the Dylan language

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

USE_PERL5=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--srcdir=${WRKSRC} --with-gc-prefix=${PREFIX}
CONFIGURE_ENV=	D2C="${WRKDIR}/d2c -p${WRKSRC}/d2c/compiler/platforms.descr"

GCCVER!=	gcc -dumpversion
PLIST_SUB=	DYLANVER="${PORTVERSION}"
.if ${GCCVER:M3.3*}!=""
PLIST_SUB+=	DYLANARCH="x86-freebsd-elf-gcc33"
.elif ${GCCVER:M3.2*}!=""
PLIST_SUB+=	DYLANARCH="x86-freebsd-elf-gcc32"
.else
PLIST_SUB+=	DYLANARCH="x86-freebsd-elf-gcc"
.endif

ONLY_FOR_ARCHS=	i386

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/dylan/%%DYLANVER%%/%%DYLANARCH%%
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
MAKEFILE=	GNUmakefile
ALL_TARGET=	default

MAN1=		d2c.1 dybug.1 make-dylan-app.1 melange.1 mindy.1 mindycomp.1 \
		mindyexec.1 parsergen.1 gobject-tool.1
MAN5=		platforms.descr.5
MAN7=		dylan.7 gwydion.7

USE_REINPLACE=	yes
CONFIGURE_ARGS+=--without-gtk

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/d2c-${PORTVERSION}-FreeBSD.gz >${WRKDIR}/d2c
	${CHMOD} ugo+x ${WRKDIR}/d2c

pre-patch:
	${REINPLACE_CMD} -e 's|libtool$$|${LIBTOOL_LIBEXECDIR}/libtool|' \
		${WRKSRC}/d2c/compiler/platforms.descr

.include <bsd.port.mk>
