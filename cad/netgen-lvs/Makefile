# $FreeBSD$

PORTNAME=	netgen
DISTVERSION=	1.5.144
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/netgen/archive/
PKGNAMESUFFIX=	-lvs

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for comparing netlists (a process known as LVS)

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/Copying

USES=		gmake python tar:tgz

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/env python3$$|#!${PYTHON_CMD}|' ${WRKSRC}/python/*.py

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
