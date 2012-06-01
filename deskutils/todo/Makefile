# ex:ts=8
# Ports collection makefile for:	todo
# Date created:			Jul 13, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	todo
PORTVERSION=	2.9
CATEGORIES=	deskutils
MASTER_SITES=	http://cloud.github.com/downloads/ginatrapani/todo.txt-cli/
DISTNAME=	todo.txt_cli-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Todo.txt Manager

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

OPTIONS_DEFINE=	BASH
BASH_DESC=	Install programmable completions for Bash

.include <bsd.port.options.mk>

NO_BUILD=	yes

PLIST_FILES=	bin/todo etc/todo.cfg

.if ${PORT_OPTIONS:MBASH}
PLIST_FILES+=	etc/bash_completion.d/todo
PLIST_DIRSTRY+=	etc/bash_completion.d
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${LOCALBASE}/bin/bash," ${WRKSRC}/todo.sh
.if ${PORT_OPTIONS:MBASH}
	@${REINPLACE_CMD} -e "s,/bin/bash,${LOCALBASE}/bin/bash," ${WRKSRC}/todo_completion
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${PREFIX}/bin/todo
	@${INSTALL_DATA} ${WRKSRC}/todo.cfg ${PREFIX}/etc/todo.cfg

post-install:
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/todo_completion ${PREFIX}/etc/bash_completion.d/todo
.endif

.include <bsd.port.mk>
