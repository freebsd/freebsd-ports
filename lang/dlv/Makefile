# New ports collection Makefile for:	dlv
# Date created:				2007-06-01
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	dlv
PORTVERSION=	20071011
CATEGORIES=	lang
MASTER_SITES=	http://www.dbai.tuwien.ac.at/research/project/dlv/ \
		http://www.dbai.tuwien.ac.at/proj/dlv/
DISTNAME=	dlv.i386-linux-elf-static.bin
EXTRACT_SUFX=

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A Disjunctive Datalog System

NO_BUILD=	yes
PLIST_FILES=	bin/dlv
ONLY_FOR_ARCHS=	i386 amd64
RESTRICTED=	Not sure if we can redistribute it

do-extract:
	${RM} -rf ${WRKDIR}
	${MKDIR} ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/dlv
	${BRANDELF} -t Linux ${PREFIX}/bin/dlv

.include <bsd.port.mk>
