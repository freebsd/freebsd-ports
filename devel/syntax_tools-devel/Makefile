# New ports collection makefile for:	syntax_tools-devel
# Date Created:				31 December 2003
# Whom:				 	chris_pressey@yahoo.ca
# Based on:	devel/syntax_tools, olgeni@FreeBSD.org, 18 July 2003
#
# $FreeBSD$
#

PORTNAME=	syntax_tools
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://user.it.uu.se/~richardc/edoc/
PKGNAMESUFFIX=	-devel
DISTNAME=	syntax_tools
DIST_SUBDIR=	erlang

MAINTAINER=	chris_pressey@yahoo.ca
COMMENT=	Erlang modules for code manipulation, unstable devel version

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

CONFLICTS=	syntax_tools-1.2*

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GMAKE=	yes

SYNTAX_TOOLS=	${PREFIX}/lib/erlang/lib/syntax_tools-${PORTVERSION}

do-install:
	@${MKDIR} ${SYNTAX_TOOLS}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${LN} -s ${DOCSDIR} ${SYNTAX_TOOLS}/doc
.endif

	@${MKDIR} ${SYNTAX_TOOLS}/src
	@${MKDIR} ${SYNTAX_TOOLS}/ebin
	@${INSTALL_DATA} ${WRKSRC}/src/*.erl ${SYNTAX_TOOLS}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${SYNTAX_TOOLS}/ebin
	@${LN} -sf ${DISTNAME}-${PORTVERSION} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
