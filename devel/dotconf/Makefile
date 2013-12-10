# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dotconf
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, powerful configuration-file parser

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=	pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIR/s|=.*|= src|' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in README argdouble caseinsensitive context duplicates errorhandler \
	fallback libpool maketest.sh modules noinline simple
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${ex} ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
