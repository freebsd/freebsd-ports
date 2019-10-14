# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dotconf
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GENTOO

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple, powerful configuration-file parser

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIR/s|=.*|= src|' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in README argdouble caseinsensitive context duplicates errorhandler \
	fallback libpool maketest.sh modules noinline simple
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${ex} ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
