# New ports collection makefile for:	dialyzer
# Date Created:				8 January 2005
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dialyzer
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.it.uu.se/research/group/hipe/dialyzer/snapshots/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Static analysis tool for Erlang/OTP applications

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|%%DIALYZER_DIR%%|${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}|g' ${WRKSRC}/setup.sh
	@${FIND} ${WRKSRC} -name .cvsignore | ${XARGS} ${RM}

do-build:
	@cd ${WRKSRC} && ./setup.sh --no_analysis ${PREFIX}/lib/erlang

do-install:
	@${MKDIR} ${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${PREFIX}/lib/erlang/lib/${PORTNAME}
	@cd ${WRKSRC} && ${CP} -r README RELEASE_NOTES dialyzer doc ebin plt src ${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${FIND} ${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION} -name \*.orig | ${XARGS} ${RM}
	@${LN} -sf ${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/dialyzer ${PREFIX}/bin/dialyzer

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
