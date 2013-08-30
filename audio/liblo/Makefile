# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	liblo
PORTVERSION=	0.27
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Lightweight Open Sound Control implementation

LICENSE=	LGPL21

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

USES=		gmake pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=		liblo.3 liblolowlevel.3 lo.h.3 lo_arg.3 lo_lowlevel.h.3 \
		lo_osc_types.h.3 lo_timetag.3 lo_types.h.3 pp.3

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README TODO

PORTEXAMPLES=	example_client example_server \
		example_tcp_echo_server nonblocking_server_example

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES

.include <bsd.port.options.mk>

post-install:
	cd ${WRKSRC}/doc/man/man3 && ${INSTALL_MAN} ${MAN3} ${MAN3PREFIX}/man/man3

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
