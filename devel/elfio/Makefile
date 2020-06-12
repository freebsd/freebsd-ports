# Created by: ijliao
# $FreeBSD$

PORTNAME=	elfio
PORTVERSION=	3.6
CATEGORIES=	devel
MASTER_SITES=	SF/elfio/ELFIO-sources/ELFIO-${PORTVERSION}

MAINTAINER=	james.wright@digital-chaos.com
COMMENT=	Small C++ library for reading and generating ELF files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${EXAMPLESDIR}

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/elfio.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/examples/ -name "*.cpp" -exec ${INSTALL_DATA} {} \
	${STAGEDIR}${EXAMPLESDIR}/ \;

.include <bsd.port.mk>
