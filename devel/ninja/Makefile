# New ports collection makefile for:	ninja
# Date created:				08 February 2011
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	ninja
PORTVERSION=	20120204
CATEGORIES=	devel
MASTER_SITES=	https://github.com/MagikBSD/ninja/tarball/${DISTVERSION}/
DISTNAME=	MagikBSD-${PORTNAME}-${DISTVERSION}-0-g${GITVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	Ninja is a small build system closest in spirit to Make

LICENSE=	AL2

CONFLICTS=	irc/ninja-[0-9]*
USE_PYTHON=	yes

GITVERSION=	ff1c488
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/MagikBSD-${PORTNAME}-${GITVERSION}

PLIST_FILES=	bin/ninja
PORTDOCS=	COPYING HACKING README manual.asciidoc

do-build:
	@(cd ${WRKSRC}; CXX=${CXX} ./bootstrap.py)

do-install:
	@${INSTALL} -m 755 ${WRKSRC}/ninja ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL} -m 644 COPYING HACKING README ${DOCSDIR})
	@(cd ${WRKSRC}/doc; ${INSTALL} -m 644 manual.asciidoc ${DOCSDIR})
.endif

.include <bsd.port.mk>
