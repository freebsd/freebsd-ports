# New ports collection makefile for:	aldo
# Date created:		16 March 2004
# Whom:			lambert@lambertfam.org
#
# $FreeBSD$
#

PORTNAME=	aldo
PORTVERSION=	0.6.11
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lambert@lambertfam.org
COMMENT=	Morse code training program

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/aldo
MAN1=	aldo.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
MAKE_ENV+=	CXX="${CXX}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aldo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aldo.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
