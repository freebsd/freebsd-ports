# New ports collection makefile for:	Togl
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	togl
PORTVERSION=	1.6
PORTREVISION=	0
CATEGORIES=	graphics tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Togl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tk OpenGL widget

EXPIRATION_DATE=2005-07-01
DEPRECATED=	Resulting application unusable, cf. PR ports/76293

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84 \
		tcl84.1:${PORTSDIR}/lang/tcl84

USE_GMAKE=	yes
USE_GL=		yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

TOGL_INSTDIR=	${PREFIX}/lib/tk8.4/${DISTNAME}
PLIST_SUB=	TOGL_INSTDIR=${TOGL_INSTDIR:S,^${PREFIX}/,,}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	@${MKDIR} ${TOGL_INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.so ${TOGL_INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/togl.h ${WRKSRC}/pkgIndex.tcl ${TOGL_INSTDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Togl.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
