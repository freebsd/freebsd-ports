# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libaux
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.freebsdbrasil.com.br/~jmelo/
DISTFILES=	libaux${EXTRACT_SUFX} libtk${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nano window toolkit and auxiliary library for OpenGL

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake
USE_GL=		glut
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	include/GL/aux.h \
		include/GL/tk.h \
		lib/libaux.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/libaux.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/aux.h ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/../libtk/tk.h ${STAGEDIR}${PREFIX}/include/GL

.include <bsd.port.mk>
