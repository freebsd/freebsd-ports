# Created by: jkoshy
# $FreeBSD$

PORTNAME=	siod
PORTVERSION=	3.4
CATEGORIES=	lang scheme
MASTER_SITES=	LOCAL/jkoshy
DISTNAME=	siod
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small footprint implementation of the Scheme programming language

BROKEN_armv6=		fails to link: final link failed: Nonrepresentable section on output
BROKEN_armv7=		fails to link: ld: siod: hidden symbol `__aeabi_uidivmod' in /usr/lib/libgcc.a(aeabi_uidivmod.o) is referenced by DSO
BROKEN_mips64=		fails to link: final link failed: Nonrepresentable section on output

USE_LDCONFIG=	yes
LLD_UNSAFE=	yes

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd
MAKE_ENV=	LD_LIBRARY_PATH=.
MAKE_JOBS_UNSAFE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/siod

.include <bsd.port.mk>
