# New ports collection makefile for:	critterding
# Date created:		15 Oct 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	critterding
DISTVERSION=	beta12
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sources

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Evolving Artificial Life

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:267:env aclocal:111:env automake:111:env libtool:22
USE_SDL=	sdl
USE_GL=		gl
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2"
CONFIGURE_ARGS=	--disable-system-ftgl
USE_GCC=	4.2+
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README AUTHORS Changelog

post-patch:
	@${REINPLACE_CMD} -e 's|../share/critterding|${DATADIR}|' \
		${WRKSRC}/src/gui/textprinter.cpp ${WRKSRC}/src/gl/glwindow.cpp

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} -fi

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
