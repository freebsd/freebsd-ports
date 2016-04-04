# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imc
PORTVERSION=	4.3
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://www.peterverthez.net/projects/imc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Compiler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-GD>=0:graphics/p5-GD \
		p5-CGI>=0:www/p5-CGI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5
GNU_CONFIGURE=	yes
NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES


post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog NEWS README THANKS Todo \
		${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.ref *.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
