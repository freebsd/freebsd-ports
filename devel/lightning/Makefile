# ex:ts=8
# Ports collection makefile for:	lightning
# Date created:			May 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lightning
PORTVERSION=	1.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates assembly language code at run-time

ONLY_FOR_ARCHS=	i386 sparc64

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"

MAN1=		lightningize.1
INFO=		lightning

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

.include <bsd.port.mk>
