# ex:ts=8
# New ports collection makefile for:	dynamechs
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dynamechs
PORTVERSION=	4.0.p1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/4.0pre1
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Multibody Dynamic Simulation Library

USE_BZIP2=	yes
USE_GL=		glut
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
CXXFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV=	OPENGLINCDIR="${LOCALBASE}/include" \
		OPENGLLIBDIR="${LOCALBASE}/lib" \
		LDFLAGS="${PTHREAD_LIBS}"
ALL_TARGET=	freebsd
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

do-configure:
	@${CP} -f ${FILESDIR}/make.platform.freebsd ${WRKSRC}/make/

do-install:
.for dir in dm dmu dmGL
	${RM} -f ${WRKSRC}/${dir}/*.orig
	@${MKDIR} ${PREFIX}/include/${PORTNAME}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.h* ${PREFIX}/include/${PORTNAME}/${dir}
	${INSTALL_DATA} ${WRKSRC}/lib/platform.freebsd/lib${dir}.so ${PREFIX}/lib
.endfor

.include <bsd.port.post.mk>
