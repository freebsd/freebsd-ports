# $FreeBSD$

PORTNAME=	common_lib
PORTVERSION=	3.3.4
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Library of commonly used Erlang functions

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		txt2tags:${PORTSDIR}/textproc/txt2tags
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	iamaleksey
GH_PROJECT=	common_lib
GH_COMMIT=	c242861
GH_TAGNAME=	${PORTVERSION}

USE_GMAKE=	yes
USE_DOS2UNIX=	Makefile
ALL_TARGET=	compile doc
USES=		iconv:build

post-extract:
	@${REINPLACE_CMD} -e "s@&lt;@<@g" -e "s@&gt;@>@g" ${WRKSRC}/doc/*.ndoc

do-install:
	@for manpage in ${WRKSRC}/doc/man/*; do \
		${MV} $${manpage} $${manpage}.src; \
		${ICONV_CMD} -f UTF-8 -t ISO-8859-1 $${manpage}.src > $${manpage}; \
	done
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.3 ${STAGEDIR}${MAN1PREFIX}/man/man3
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}/src

.include <bsd.port.mk>
