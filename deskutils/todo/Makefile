# ex:ts=8
# Ports collection makefile for:	todo
# Date created:			Jul 13, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	todo
PORTVERSION=	2.4
CATEGORIES=	deskutils
MASTER_SITES=	http://cloud.github.com/downloads/ginatrapani/todo.txt-cli/
DISTNAME=	todo.txt_cli-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Todo.txt Manager

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes

PLIST_FILES=	bin/todo etc/todo.cfg

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${LOCALBASE}/bin/bash," ${WRKSRC}/todo.sh

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${PREFIX}/bin/todo
	@${INSTALL_DATA} ${WRKSRC}/todo.cfg ${PREFIX}/etc/todo.cfg

.include <bsd.port.mk>
