# ex:ts=8
# New ports collection makefile for:	rlwrap
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rlwrap
PORTVERSION=	0.18
CATEGORIES=	devel
MASTER_SITES=	http://utopia.knoware.nl/~hlub/uck/rlwrap/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Readline wrapper

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	ptyttylib_cv_ptys=BSD

MAN1=	rlwrap.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
IGNORE=		"Requires readline 4.2 or newer, only available in recent versions of FreeBSD 5.x"
.endif

.include <bsd.port.post.mk>
