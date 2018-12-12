# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	ems-flasher
PORTVERSION=	0.03
PORTREVISION=	9
CATEGORIES=	comms
MASTER_SITES=	http://lacklustre.net/projects/ems-flasher/ \
		https://cooltrainer.org/freebsd-ports/ems-flasher/

MAINTAINER=	root@cooltrainer.org
COMMENT=	Utility to flash ROM images to the EMS USB 64mb flash cart

LICENSE=	MIT

USES=		gmake tar:tgz
CFLAGS+=	-g -Wall
LDFLAGS+=	-lusb
USE_GCC=	yes

PLIST_FILES=	bin/ems-flasher

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ems-flasher ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
