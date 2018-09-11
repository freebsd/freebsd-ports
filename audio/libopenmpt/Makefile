# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopenmpt
PORTVERSION=	0.3.11
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module music library based on OpenMPT

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	OpenMPT
GH_PROJECT=	openmpt
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(PREFIX)/share/doc/libopenmpt/examples|${EXAMPLESDIR}|g' \
			${WRKSRC}/Makefile

.include <bsd.port.mk>
