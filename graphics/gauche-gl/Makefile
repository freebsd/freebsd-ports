# New ports collection makefile for:	Gauche-gl
# Date created:				16 December 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gl
PORTVERSION=	0.4.4
CATEGORIES=	graphics scheme
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gauche
PKGNAMEPREFIX=	gauche-
DISTNAME=	Gauche-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org
COMMENT=	OpenGL binding for Gauche

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GL=		glut
GNU_CONFIGURE=	yes
USE_GCC=	3.4+
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib

EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
PLIST_SUB=	VERSION="`gauche-config -V`" \
		TARGET="${CONFIGURE_TARGET}"

.if !defined(NOPORTDOCS)
INFO=		gauche-gl-refe gauche-gl-refj
.endif

post-patch:
	${REINPLACE_CMD} s/VESRION/VERSION/ ${WRKSRC}/src/gen-ptrs.scm

do-install:
	cd ${WRKSRC}/src; ${MAKE} ${INSTALL_TARGET}
	cd ${WRKSRC}/lib; ${MAKE} ${INSTALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
.for i in gauche-gl-refe.info gauche-gl-refj.info
	${GZCAT} ${WRKSRC}/doc/${i}.gz >${PREFIX}/info/${i}
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
