# New ports collection makefile for:	objprelink
# Date Created:				18th November 2001
# Whom:				Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	objprelink
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://objprelink.sourceforge.net/ \
		${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=     binutils/releases
DISTFILES=	objprelink-1.c binutils-${BINUTILS_VER}.tar.bz2

MAINTAINER=	dominic_marks@btinternet.com

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

ONLY_FOR_ARCHS=	i386
BINUTILS_VER=	2.11.2
USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/objprelink

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAR} xfy ${DISTDIR}/binutils-${BINUTILS_VER}.tar.bz2
	@${MV} ${WRKSRC}/binutils-${BINUTILS_VER} ${WRKSRC}/binutils
	@${CP} ${DISTDIR}/objprelink-1.c ${WRKSRC}

do-configure:
	@cd ${WRKSRC}/binutils/bfd/ && \
		${SETENV} LDFLAGS="$$LDFLAGS -L${LOCALBASE}/lib" \
		CFLAGS="$$CFLAGS -I${LOCALBASE}/include" \
		CPPFLAGS="$$CPPFLAGS -I${LOCALBASE}/include" ./configure \
		--disable-shared --enable-static
	@cd ${WRKSRC}/binutils/libiberty/ && \
		${SETENV} LDFLAGS="$$LDFLAGS -L${LOCALBASE}/lib" \
		CFLAGS="$$CFLAGS -I./../include" \
		CPPFLAGS="$$CPPFLAGS -I./../include" ./configure \
		--disable-shared --enable-static

do-build:
.for DIR in bfd libiberty
	@cd ${WRKSRC}/binutils/${DIR}/ && ${GMAKE}
.endfor
	@${CC} ${CFLAGS} -static -o ${WRKSRC}/objprelink ${WRKSRC}/objprelink-1.c \
		${WRKSRC}/binutils/bfd/libbfd.a \
		${WRKSRC}/binutils/libiberty/libiberty.a \
		-I${WRKSRC}/binutils/include -I${WRKSRC}/binutils/bfd \
		-I${WRKSRC}/binutils/libiberty \
		-L${LOCALBASE}/lib -lintl -liconv

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/objprelink ${PREFIX}/bin

.include <bsd.port.mk>
