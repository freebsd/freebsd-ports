PORTNAME=	todo
PORTVERSION=	2.13.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/todotxt/todo.txt-cli/releases/download/v${PORTVERSION}/
DISTNAME=	todo.txt_cli-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Todo.txt Manager
WWW=		http://todotxt.org/ \
		https://github.com/todotxt/todo.txt-cli

LICENSE=	GPLv3

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/todo.sh \
		etc/todo.cfg \
		etc/bash_completion.d/todo

SHEBANG_FILES=	todo.sh todo_completion

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/todo.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${STAGEDIR}${PREFIX}/bin/todo.sh
	${INSTALL_DATA} ${WRKSRC}/todo.cfg ${STAGEDIR}${PREFIX}/etc/todo.cfg
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/todo_completion ${STAGEDIR}${PREFIX}/etc/bash_completion.d/todo

.include <bsd.port.mk>
