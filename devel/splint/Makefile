# New ports collection makefile for:	splint
# Date created: 	9 September 1996
# Whom:			moeding
#
# $FreeBSD$
#

PORTNAME=	splint
PORTVERSION=	3.1.1
PORTREVISION=	2
CATEGORIES=	devel security
MASTER_SITES=	http://www.splint.org/downloads/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	andrew.nau.ua@gmail.com
COMMENT=	A tool for statically checking sourcecode for security vulnerabilities

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		splint.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/Headers/constants.h

.include <bsd.port.mk>
