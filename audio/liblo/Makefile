# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	liblo
PORTVERSION=	0.28
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	koalative@gmail.com
COMMENT=	Lightweight Open Sound Control implementation

LICENSE=	LGPL21

USES=		gmake libtool:oldver pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

SHLIB_VER=	9
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"

PORTDOCS=	*
PORTEXAMPLES=	example_client example_server \
		example_tcp_echo_server nonblocking_server_example

OPTIONS_DEFINE=	DOXYGEN DOCS EXAMPLES
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

.include <bsd.port.options.mk>

post-patch:
.if ${ARCH} == i386 || ${ARCH} == powerpc
	@${REINPLACE_CMD} -e 's,deadbeef,, ; s,f00baa23,,' \
		${WRKSRC}/lo/lo_macros.h
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblo.so.${SHLIB_VER}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MDOXYGEN}
	(cd ${WRKSRC}/doc/man/man3 && ${INSTALL_MAN} l*.3 p*.3 \
		${STAGEDIR}${MAN3PREFIX}/man/man3/)
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
