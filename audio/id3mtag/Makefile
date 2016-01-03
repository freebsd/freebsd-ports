# Created by: squell@alumina.nl
# $FreeBSD$

PORTNAME=	id3mtag
PORTVERSION=	0.80
CATEGORIES=	audio
MASTER_SITES=	http://github.com/squell/id3/releases/download/${PORTVERSION}/
DISTNAME=	id3-${PORTVERSION}

MAINTAINER=	squell@alumina.nl
COMMENT=	Mass tagging utility for audio files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

MAKEFILE=	makefile
ALL_TARGET=	build

PLIST_FILES=	bin/id3 man/man1/id3.1.gz
PORTDOCS=	README CHANGES

OPTIONS_DEFINE=	DOCS BASH
BASH_DESC=	Support for bash auto-completion
BASH_PLIST_FILES=	share/bash-completion/completions/id3

USES=		iconv

CFLAGS+=	-I${ICONV_INCLUDE_PATH}
LDFLAGS+=	-L${ICONV_PREFIX}/lib ${ICONV_LIB}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/id3.man ${STAGEDIR}${MANPREFIX}/man/man1/id3.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/bash/complete ${STAGEDIR}${PREFIX}/${BASH_PLIST_FILES}

.include <bsd.port.mk>
