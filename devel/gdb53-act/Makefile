# Ports collection makefile for:	GDB 5.3-act
# Date created:				8 August 2003
# Whom:					John R. Shannon <john@johnrshannon.com>
#
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=    5.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.johnrshannon.com/download/
PKGNAMESUFFIX=	-act
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	john@johnrshannon.com
COMMENT=	GDB 5.3 modified by ACT for Ada programming language

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	bin/gdbada
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=ada
CONFIGURE_ARGS+=	--disable-nls

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		Does not compile on !i386 and !alpha
.endif

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo
	${LN} -sf ${FILESDIR}/freebsd-uthread.c ${FILESDIR}/kvm-fbsd.c \
		${WRKSRC}/gdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/gdbada

.include <bsd.port.post.mk>
