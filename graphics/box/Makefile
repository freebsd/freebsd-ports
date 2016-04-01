# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	box
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}c/Box%20-%20the%20compiler/${DISTNAME}/
DIST_SUBDIR=	box

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler for box, the figure description language

LICENSE=	GPLv2+ LGPL3+
LICENSE_COMB=	multi

BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man
LIB_DEPENDS=	libcairo.so:graphics/cairo

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cairo
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
TEST_TARGET=	check

PORTDOCS=	AUTHORS ChangeLog README STYLE
PORTEXAMPLES=	*

PLIST_SUB=	PLIST_VER=${PORTVERSION:R}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${TOUCH} ${WRKSRC}/man/${PORTNAME}.sgml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
