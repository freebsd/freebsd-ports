# Created by: ijliao
# $FreeBSD$

PORTNAME=	todo
PORTVERSION=	2.10
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${GH_TAGNAME}/
DISTNAME=	todo.txt_cli-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Todo.txt Manager

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

CONFLICTS_INSTALL=	devtodo-[0-9]*

OPTIONS_DEFINE=	BASH
OPTIONS_SUB=	yes
BASH_DESC=	Install programmable completions for Bash

NO_BUILD=	yes
USES=		shebangfix

PLIST_FILES=	bin/todo etc/todo.cfg \
		%%BASH%%etc/bash_completion.d/todo

GH_ACCOUNT=	ginatrapani
GH_PROJECT=	todo.txt-cli
GH_TAGNAME=	v${PORTVERSION}

SHEBANG_FILES=	todo.sh todo_completion

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${STAGEDIR}${PREFIX}/bin/todo
	${INSTALL_DATA} ${WRKSRC}/todo.cfg ${STAGEDIR}${PREFIX}/etc/todo.cfg
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/todo_completion ${STAGEDIR}${PREFIX}/etc/bash_completion.d/todo

.include <bsd.port.mk>
