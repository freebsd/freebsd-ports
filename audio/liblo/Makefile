# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	liblo
PORTVERSION=	0.31
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight Open Sound Control implementation

LICENSE=	LGPL21

USES=		gmake libtool pathfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	example_client \
		example_server \
		example_tcp_echo_server \
		nonblocking_server_example

OPTIONS_DEFINE=	DOXYGEN DOCS EXAMPLES
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

.include <bsd.port.options.mk>

post-patch:
.if ${ARCH} == i386 || ${ARCH} == powerpc
	@${REINPLACE_CMD} -e 's|deadbeef||; s|f00baa23||' ${WRKSRC}/lo/lo_macros.h
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog NEWS README TODO ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	cd ${WRKSRC}/doc/man/man3 && ${INSTALL_MAN} l*.3 p*.3 ${STAGEDIR}${PREFIX}/share/man/man3/
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_SCRIPT} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
