# New ports collection makefile for:	syntax_tools
# Date Created:				18 July 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	syntax_tools
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.erlang.org/contrib/ \
		http://erlang.stacken.kth.se/contrib/ \
		http://www.csd.uu.se/ftp/mirror/erlang/contrib/ \
		http://www.serc.rmit.edu.au/mirrors/ose_mirror/contrib/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang modules for code manipulation

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

CONFLICTS=	syntax_tools-1.3*

PLIST_SUB=	VERSION="${PORTVERSION}"

SYNTAX_TOOLS=	${PREFIX}/lib/erlang/lib/syntax_tools-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-extract:
		@${RM} ${WRKSRC}/demo.erl ${WRKSRC}/test.erl

do-build:
		@cd ${WRKSRC} && erlc *.erl

do-install:
		@${MKDIR} ${SYNTAX_TOOLS}
		@${MKDIR} ${SYNTAX_TOOLS}/src
		@${MKDIR} ${SYNTAX_TOOLS}/ebin
		@${MKDIR} ${SYNTAX_TOOLS}/doc
		@${INSTALL_DATA} ${WRKSRC}/*.erl ${SYNTAX_TOOLS}/src
		@${INSTALL_DATA} ${WRKSRC}/*.beam ${SYNTAX_TOOLS}/ebin
		@${INSTALL_DATA} ${WRKSRC}/doc/* ${SYNTAX_TOOLS}/doc
		@${LN} -sf ${DISTNAME} ${PREFIX}/lib/erlang/lib/syntax_tools

.include <bsd.port.post.mk>
