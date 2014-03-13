# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	ems-flasher
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://lacklustre.net/redmine/attachments/download/10/ \
	http://update.cooltrainer.org/freebsd-ports/comms/ems-flasher/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@cooltrainer.org
COMMENT=	Utility to flash ROM images to the EMS USB 64mb flash cart

LICENSE=	MIT

USES=		gmake
CFLAGS+=	-g -Wall
LDFLAGS+=	-lusb
USE_GCC=	yes

PLIST_FILES=	bin/ems-flasher

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
IGNORE=	does not compile with the old USB stack
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ems-flasher ${PREFIX}/bin

.include <bsd.port.post.mk>
