# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-gen
PORTVERSION=	0.16
CATEGORIES=	devel
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	C interface generator for the Pure language

LICENSE=	BSD

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-language-c>=0.3.2:${PORTSDIR}/devel/hs-language-c

NO_STAGE=	yes

CC=		gcc

USES=		pure:ffi
USE_GCC=	4.6+

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME} \
		lib/${PORTNAME}/dump-ast
PLIST_DIRS=	lib/${PORTNAME}

PORTDOCS=	README README.dump-ast

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
