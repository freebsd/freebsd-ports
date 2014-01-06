# Created by: gahr
# $FreeBSD$

PORTNAME=	combat
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	http://www.fpx.de/Combat/download/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	A CORBA ORB implementation in Tcl

LICENSE=	BSD

DEPRECATED=	depends on expired devel/mico
EXPIRATION_DATE=2014-01-22

LIB_DEPENDS=	libitcl.so:${PORTSDIR}/lang/itcl
RUN_DEPENDS=	idl:${PORTSDIR}/devel/mico

OPTIONS_DEFINE=	DOCS EXAMPLES

USES+=		tcl:run
NO_BUILD=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-patch:
	${FIND} ${WRKSRC} -name dotest | ${XARGS} \
	    ${REINPLACE_CMD} -i '' -e 's|tclsh8.5|${TCLSH}|g'
	${REINPLACE_CMD} -e 's|%%TCLSH%%|${TCLSH}|' \
	    ${WRKSRC}/bin/idl2tcl ${WRKSRC}/bin/iordump

do-install:
	cd ${WRKSRC}/orb && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/combat
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/combat
	${INSTALL_SCRIPT} ${WRKSRC}/bin/idl2tcl ${STAGEDIR}${PREFIX}/bin/combat
	${INSTALL_SCRIPT} ${WRKSRC}/bin/iordump ${STAGEDIR}${PREFIX}/bin/combat
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/combat.pdf ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endif

regression-test:
	cd ${WRKSRC}/test && ${MAKE} test

.include <bsd.port.mk>
