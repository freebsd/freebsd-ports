# New ports collection makefile for:	zoom
# Date created:				May 07 2003
# Whom:					Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	zoom
PORTVERSION=	1.0.1a
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.logicalshift.demon.co.uk/unix/${PORTNAME}/
DISTFILES=	${DISTFILE_SRC} ${DISTFILE_PATCH}
EXTRACT_ONLY=	${DISTFILE_SRC}

MAINTAINER=	Jan.Stocker@t-online.de
COMMENT=	Z-Interpreter for X with full V6 support

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

NOT_FOR_ARCHS=	sparc64

USE_PERL5=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DISTFILE_SRC=	${PORTNAME}-1.0.1.tar.gz
DISTFILE_PATCH=	zoom-1.0.1-1.0.1a.patch
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAKE_ENV=	${CONFIGURE_ENV}

post-extract:
	${MV} ${WRKDIR}/${PORTNAME}-1.0.1 ${WRKSRC}
	@cd ${WRKDIR} && \
		${PATCH} < ${DISTDIR}/${DISTFILE_PATCH}

.include <bsd.port.mk>
