# New ports collection makefile for:	ninja
# Date created:				08 February 2011
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	ninja
PORTVERSION=	20110208
CATEGORIES=	devel
MASTER_SITES=	http://files.roorback.net/src/

MAINTAINER=	magik@roorback.net
COMMENT=	Ninja is a small build system closest in spirit to Make

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

LICENSE=	ASL
CONFLICTS=	irc/ninja-[0-9]*

PLIST_FILES=	bin/ninja
PORTDOCS=	COPYING HACKING README manual.asciidoc todo

post-patch:
	@${REINPLACE_CMD} \
	    -e 's|/bin/bash|/bin/sh|' \
	    -e 's|conf_cflags = -O2|conf_cflags = ${CXXFLAGS} -I${LOCALBASE}/include|' \
	    -e 's|conf_ldflags = -s|conf_ldflags = -s -L${LOCALBASE}/lib -lexecinfo|' \
	    -e 's|g++|g++ -I${LOCALBASE}/include -L${LOCALBASE}/lib -lexecinfo|' \
	    ${WRKSRC}/bootstrap.sh

do-build:
	@(cd ${WRKSRC}; ./bootstrap.sh)

do-install:
	@${INSTALL} -m 755 ${WRKSRC}/ninja ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL} -m 644 ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
