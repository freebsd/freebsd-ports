# Created by: Juergen Unger <j.unger@choin.net>
# $FreeBSD$

PORTNAME=	fly
PORTVERSION=	2.0.1
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://fossies.org/unix/www/ \
		http://martin.gleeson.com/fly/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple drawing language to generate GIFs on the fly

LIB_DEPENDS=	libgd.so:graphics/gd

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/fly

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include fly.c -o fly \
		-L${LOCALBASE}/lib -lgd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
