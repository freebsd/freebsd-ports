# New ports collection makefile for:	splint
# Date created: 	9 September 1996
# Whom:			moeding
#
# $FreeBSD$
#

PORTNAME=	splint
PORTVERSION=	3.0.1.6
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://www.splint.org/downloads/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

MAN1=		splint.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
