# Created by: arved
# $FreeBSD$

PORTNAME=	dlv
PORTVERSION=	20121217
CATEGORIES=	lang
MASTER_SITES=	http://www.dlvsystem.com/files/
DISTNAME=	dlv.i386-linux-elf-static.bin
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Disjunctive Datalog System

BROKEN=		unfetchable

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
PLIST_FILES=	bin/dlv
ONLY_FOR_ARCHS=	i386 amd64
RESTRICTED=	Not sure if we can redistribute it

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/dlv

.include <bsd.port.mk>
