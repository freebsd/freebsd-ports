# ex:ts=8
# New ports collection makefile for:	rlwrap
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rlwrap
PORTVERSION=	0.21
CATEGORIES=	devel
MASTER_SITES=	http://utopia.knoware.nl/~hlub/uck/rlwrap/

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Readline wrapper

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	ptyttylib_cv_ptys=BSD

MAN1=	rlwrap.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
# This port requires readline 4.2 or newer, which is only available
# in the base system in FreeBSD 5.x.
BUILD_DEPENDS+=		${PREFIX}/lib/libreadline.so.5:${PORTSDIR}/devel/readline
RUN_DEPENDS+=		${BUILD_DEPENDS}
# Make sure the dynamic linker does not pick up
# the older libreadline library from the base system.
LDFLAGS+=		-rpath ${PREFIX}/lib
.endif

.include <bsd.port.post.mk>
