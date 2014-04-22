# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-ffi
PORTVERSION=	0.13
CATEGORIES=	devel
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to libffi

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS+=	libffi.so:${PORTSDIR}/devel/libffi

USES=		pure

PLIST_FILES=	lib/pure/ffi.pure \
		lib/pure/ffi.so

PORTDOCS=	README

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
