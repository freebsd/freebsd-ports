# $FreeBSD$

PORTNAME=	oserl
PORTVERSION=	3.2.4
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	SMPP library for Erlang

BROKEN=		fails to build

BUILD_DEPENDS=	erlc:lang/erlang \
		txt2tags:textproc/txt2tags
RUN_DEPENDS=	erl:lang/erlang \
		erlang-common_lib>=3.3.4:devel/erlang-common_lib

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	iamaleksey

USES=		dos2unix gmake iconv
ALL_TARGET=	compile doc
DOS2UNIX_GLOB=	Makefile *.hrl *.erl

post-extract:
# Trick rebar into locating the oserl include files (see also patch-rebar.config)
	@${LN} -s ${WRKSRC} ${WRKDIR}/${PORTNAME}
	@${REINPLACE_CMD} -e "s@&lt;@<@g" -e "s@&gt;@>@g" ${WRKSRC}/doc/*.ndoc

do-install:
	@for manpage in ${WRKSRC}/doc/man/*; do \
		${MV} $${manpage} $${manpage}.src; \
		${ICONV_CMD} -f UTF-8 -t ISO-8859-1 $${manpage}.src > $${manpage}; \
	done
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.3 ${STAGEDIR}${MAN1PREFIX}/man/man3
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/src

.include <bsd.port.mk>
