# Created by: Murray Stokely <murray@cdrom.com>
# $FreeBSD$

PORTNAME=	nasm
PORTVERSION=	2.10.09
PORTEPOCH=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://www.nasm.us/pub/nasm/releasebuilds/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-xdoc${EXTRACT_SUFX}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	General-purpose multi-platform x86 and amd64 assembler

LICENSE=	BSD

USE_XZ=	yes
GNU_CONFIGURE=	yes
USES=	gmake	# parallel builds (-jX) are broken with BSD make(1)
MAKE_ARGS+=	INSTALLROOT=${STAGEDIR}
INSTALL_TARGET=	install install_rdf

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/nasmdoc.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
