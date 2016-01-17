# Created by: ijliao
# $FreeBSD$

PORTNAME=	elfio
PORTVERSION=	1.0.3
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/ELFIO-sources/ELFIO-${PORTVERSION}
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for reading and generating files in the ELF binary format

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf libtool
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	EXAMPLES DOCS
OPTIONS_SUB=	yes

post-patch:
	@(${FIND} ${WRKSRC}/ -name Makefile.am | \
		${XARGS} ${REINPLACE_CMD} -E -e 's,(libELFIO)\.a,\1.la,g')

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in elf11g.zip tutorial.docbook tutorial.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/Examples/ -name "*.cpp" -exec ${INSTALL_DATA} {} \
		${STAGEDIR}${EXAMPLESDIR}/ \;

.include <bsd.port.mk>
