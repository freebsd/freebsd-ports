# New ports collection makefile for:	Gauche-gl
# Date created:				16 December 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gl
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	graphics scheme
MASTER_SITES=	SF/gauche/Gauche-gl
PKGNAMEPREFIX=	gauche-
DISTNAME=	Gauche-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	OpenGL binding for Gauche

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_XORG=	ice sm
USE_GL=		glut
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
PLIST_SUB=	TARGET="${CONFIGURE_TARGET}"

.if !defined(NOPORTDOCS)
INFO=		gauche-gl-refe gauche-gl-refj
.endif

do-install:
	cd ${WRKSRC}/src; ${MAKE} ${INSTALL_TARGET}
	cd ${WRKSRC}/lib; ${MAKE} ${INSTALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
.for i in gauche-gl-refe.info gauche-gl-refj.info
	${GZCAT} ${WRKSRC}/doc/${i}.gz >${PREFIX}/info/${i}
.endfor
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
