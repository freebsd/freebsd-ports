# New ports collection makefile for:	xvid
# Date created:		04 April 2002
# Whom:			Michael Nottebrock <michaelnottebrock@gmx.net> et al
#
# $FreeBSD$
#

PORTNAME=	xvid
PORTVERSION=	0.9.0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cvs.xvid.org/downloads/xvidcore-0.9.0/
DISTNAME=	xvidcore-${PORTVERSION}

MAINTAINER=	michaelnottebrock@gmx.net

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm

MAKEFILE=	Makefile.linuxx86
ONLY_FOR_ARCHS=	i386 alpha sparc64
USE_AUTOCONF_VER=	253
USE_AUTOMAKE=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_WRKSRC=	${WRKDIR}
WRKSRC=			${WRKDIR}/${DISTNAME}/build/generic

# XXX - compatility header installed for mplayer-devel port's benefit
EXTRA_HEADER_FILES=	divx4.h

# trick to detect existence of stdint.h
# amongst other things
pre-configure:
.for file in configure.in config.h.in
	@ ${CP} ${FILESDIR}/${file} ${WRKDIR}
.endfor

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/libxvidcore.so ${PREFIX}/lib/libxvidcore.so.0
	@ ${LN} -s libxvidcore.so.0 ${PREFIX}/lib/libxvidcore.so
	@ ${INSTALL_DATA} ${WRKSRC}/../../src/xvid.h ${PREFIX}/include
# XXX - compatility header installed for mplayer's benefit
.for header in ${EXTRA_HEADER_FILES}
	@ ${INSTALL_DATA} ${WRKSRC}/../../src/${header} ${PREFIX}/include
.endfor

.include <bsd.port.pre.mk>

CFLAGS+=	-DLINUX

.if ${ARCH:L} == i386
CFLAGS+=	-DARCH_X86
.elif ${ARCH:L} == alpha
CFLAGS+=	-DARCH_PPC
.elif ${ARCH:L} == sparc64
CFLAGS+=	-DARCH_SPARC
.endif

.include <bsd.port.post.mk>
