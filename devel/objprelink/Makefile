# New ports collection makefile for:	objprelink
# Date Created:				18th November 2001
# Whom:				Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	objprelink
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	http://leon.bottou.com/objprelink/ \
		${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=     binutils/releases
DISTFILES=	objprelink.c.gz binutils-${BINUTILS_VER}.tar.bz2

MAINTAINER=	dominic_marks@btinternet.com

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

ONLY_FOR_ARCHS=	i386
BINUTILS_VER=	2.11.2
USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/objprelink

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAR} xfy ${DISTDIR}/binutils-${BINUTILS_VER}.tar.bz2
	@${MV} ${WRKSRC}/binutils-${BINUTILS_VER} ${WRKSRC}/binutils
	@cd ${WRKSRC} && ${GZIP_CMD} -dc ${DISTDIR}/objprelink.c.gz \
		> ${WRKSRC}/objprelink.c

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
	@${CC} ${CFLAGS} -static -o ${WRKSRC}/objprelink ${WRKSRC}/objprelink.c \
		${WRKSRC}/binutils/bfd/libbfd.a \
		${WRKSRC}/binutils/libiberty/libiberty.a \
		-I${WRKSRC}/binutils/include -I${WRKSRC}/binutils/bfd \
		-I${WRKSRC}/binutils/libiberty \
		-L${LOCALBASE}/lib -lintl

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/objprelink ${PREFIX}/bin

.include <bsd.port.mk>
