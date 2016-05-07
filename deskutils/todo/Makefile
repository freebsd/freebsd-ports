# Created by: ijliao
# $FreeBSD$

PORTNAME=	todo
PORTVERSION=	2.10
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Todo.txt Manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

CONFLICTS_INSTALL=	devtodo-[0-9]*

NO_ARCH=	yes
NO_BUILD=	yes
USES=		shebangfix

PLIST_FILES=	bin/todo \
		etc/todo.cfg \
		etc/bash_completion.d/todo

GH_ACCOUNT=	ginatrapani
GH_PROJECT=	todo.txt-cli
USE_GITHUB=	yes

SHEBANG_FILES=	todo.sh todo_completion

post-patch:
	@${REINPLACE_CMD} -e 's|@DEV_VERSION@|${PORTVERSION}|' ${WRKSRC}/todo.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${STAGEDIR}${PREFIX}/bin/todo
	${INSTALL_DATA} ${WRKSRC}/todo.cfg ${STAGEDIR}${PREFIX}/etc/todo.cfg
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/todo_completion ${STAGEDIR}${PREFIX}/etc/bash_completion.d/todo

.include <bsd.port.mk>
