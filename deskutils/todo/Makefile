# ex:ts=8
# Ports collection makefile for:	todo
# Date created:			Jul 13, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	todo
PORTVERSION=	1.6
CATEGORIES=	deskutils
MASTER_SITES=	http://todotxt.com/library/todo.sh/
DISTNAME=	todo.sh

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Todo.txt Managers

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/todo etc/dot.todo

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/sh,${LOCALBASE}/bin/bash," ${WRKSRC}/todo.sh

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${PREFIX}/bin/todo
	@${INSTALL_DATA} ${WRKSRC}/.todo ${PREFIX}/etc/dot.todo

.include <bsd.port.mk>
