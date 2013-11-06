# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-readline
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Readline interface for the Pure language

LICENSE=	BSD GPLv3
LICENSE_COMB=	dual

USES=		pure

PLIST_FILES=	lib/pure/readline.pure \
		lib/pure/readline.so

NO_STAGE=	yes

PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
