# Ports collection makefile for:	box
# Date created:		2010-11-20
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	box
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}c/Box%20-%20the%20compiler/${DISTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler for box, the figure description language

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cairo
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

MAN1=		${PORTNAME}.1

PLIST_SUB+=	PLIST_VER="0.3"

post-patch:
	${TOUCH} ${WRKSRC}/man/${PORTNAME}.sgml

check regression-test: build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check)

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
