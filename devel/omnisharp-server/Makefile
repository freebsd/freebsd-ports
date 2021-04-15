# Created by: Richard Gallamore <ultima@FreeBSD.org>

PORTNAME=	omnisharp-server
DISTVERSION=	g20150729
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	HTTP wrapper around NRefactory for C\# editor plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		mono
USE_GITHUB=	yes
GH_ACCOUNT=	OmniSharp
GH_TAGNAME=	e1902915c
GH_TUPLE=	icsharpcode:NRefactory:3f78bdbed:nrefactory/NRefactory \
		jbevain:cecil:4770957a0:cecil/cecil

PORTSCOUT=	skipv:mono-2.10.8

do-build:
		(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		xbuild /property:Configuration=Release)

do-install:
		(cd ${WRKSRC}/OmniSharp/bin && ${COPYTREE_SHARE} \
		"Release" ${STAGEDIR}/${DATADIR}/bin)

.include <bsd.port.mk>
