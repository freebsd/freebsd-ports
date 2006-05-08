# New ports collection makefile for:    GShisen
# Date created:         12 Jun 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gshisen
PORTVERSION=	1.2.0
CATEGORIES=	games
MASTER_SITES=	http://www.gnustep.it/enrico/gshisen/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Mahjongg-kind of game that uses the GNUstep toolkit

USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=

post-patch:
	${REINPLACE_CMD} -e 's|)/Makefiles|)/Library/Makefiles|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
# Fatal error 'longjmp()ing between thread contexts is undefined by POSIX 1003.1'
#  at line ? in file src/lib/libc_r/uthread/uthread_jmp.c (errno = ?)
# Abort trap (core dumped)
BROKEN=		longjmp()ing between thread contexts in src/lib/libc_r/uthread/uthread_jmp.c
.endif

.include <bsd.port.post.mk>
