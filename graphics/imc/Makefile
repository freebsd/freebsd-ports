# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imc
PORTVERSION=	4.3
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.peterverthez.net/projects/imc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Compiler

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README THANKS Todo

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.html *.ref *.txt

PORTEXAMPLES=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
