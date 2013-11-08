# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	liblo
PORTVERSION=	0.27
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lightweight Open Sound Control implementation

LICENSE=	LGPL21

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

USES=		gmake pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README TODO

PORTEXAMPLES=	example_client example_server \
		example_tcp_echo_server nonblocking_server_example

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	(cd ${WRKSRC}/doc/man/man3 && ${INSTALL_MAN} l*.3 p*.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/)

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
