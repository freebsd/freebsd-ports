# ex:ts=8
# ports collection makefile for:	cproto
# Date created:				2000 Feb. 13
# Whom:					Abel Chow <abel_chow@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	cproto
PORTVERSION=	4.7d
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/cproto/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	Generate C function prototypes and convert function definitions

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		cproto.1
PLIST_FILES=	bin/cproto

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\(define\ MAX_INC_DEPTH\) 15|\1 25|' \
		-e 's|\(define MAX_TEXT_SIZE\) 256|\1 4096|' \
			${WRKSRC}/system.h
	@${REINPLACE_CMD} -e 's|mktemp|mkstemp|' \
		${WRKSRC}/${PORTNAME}.c

.include <bsd.port.mk>
