# ex:ts=8
# New ports collection makefile for:	dynamechs
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dynamechs
PORTVERSION=	4.0.p1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Multibody Dynamic Simulation Library

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_ENV=	OPENGLINCDIR="${X11BASE}/include" \
		OPENGLLIBDIR="${X11BASE}/lib" \
		CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
ALL_TARGET=	freebsd
INSTALLS_SHLIB=	yes

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
