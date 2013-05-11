# Created by: ijliao
# $FreeBSD$

PORTNAME=	ragel
PORTVERSION=	6.8
CATEGORIES=	devel
MASTER_SITES=	http://www.complang.org/ragel/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Compile regular languages into executable C/C++ code

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build
CONFIGURE_ARGS+=	--enable-manual
BUILD_DEPENDS+=	fig2dev:${PORTSDIR}/print/transfig
PLIST_SUB+=	DOCS=""
.else
PLIST_SUB+=	DOCS="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/test; ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
