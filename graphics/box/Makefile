# Ports collection makefile for:	box
# Date created:		2010-11-20
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	box
PORTVERSION=	0.2.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}c/Box%20-%20the%20compiler/${DISTNAME}/

MAINTAINER=	corky1951@comcast.net
COMMENT=	Compiler for box, the figure description language

BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARG+=	--with-cairo

MAN1=		${PORTNAME}.1

post-patch:
	${TOUCH} ${WRKSRC}/man/${PORTNAME}.sgml

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
