# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	box
PORTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}c/Box%20-%20the%20compiler/${DISTNAME}/
DIST_SUBDIR=	box

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Compiler for box, the figure description language

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man
LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cairo
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

MAN1=		${PORTNAME}.1

PORTDOCS=	AUTHORS ChangeLog README STYLE TODO
PORTEXAMPLES=	*

PLIST_SUB+=	PLIST_VER=${PORTVERSION:R}

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	${TOUCH} ${WRKSRC}/man/${PORTNAME}.sgml

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
