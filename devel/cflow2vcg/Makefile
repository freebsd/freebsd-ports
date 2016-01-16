# Created by: ijliao
# $FreeBSD$

PORTNAME=	cflow2vcg
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert the result of the cflow utility in a VCG format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/cflow* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
