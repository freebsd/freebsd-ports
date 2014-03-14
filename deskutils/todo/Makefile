# Created by: ijliao
# $FreeBSD$

PORTNAME=	todo
PORTVERSION=	2.9
CATEGORIES=	deskutils
MASTER_SITES=	http://cloud.github.com/downloads/ginatrapani/todo.txt-cli/
DISTNAME=	todo.txt_cli-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Todo.txt Manager

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

CONFLICTS=	devtodo-[0-9]*

OPTIONS_DEFINE=	BASH
BASH_DESC=	Install programmable completions for Bash

NO_BUILD=	yes
USES=		shebangfix

PLIST_FILES=	bin/todo etc/todo.cfg

SHEBANG_FILES=	todo.sh todo_completion

BASH_PLIST_FILES=	etc/bash_completion.d/todo
BAHS_PLIST_DIRSTRY=	etc/bash_completion.d

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${STAGEDIR}${PREFIX}/bin/todo
	@${INSTALL_DATA} ${WRKSRC}/todo.cfg ${STAGEDIR}${PREFIX}/etc/todo.cfg
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/todo_completion ${STAGEDIR}${PREFIX}/etc/bash_completion.d/todo

.include <bsd.port.mk>
