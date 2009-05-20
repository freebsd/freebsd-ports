# New ports collection makefile for:	naev
# Date created:		2009-04-26
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	naev
PORTVERSION=	0.3.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A 2d action/rpg space game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/ndata-${PORTVERSION}:${PORTSDIR}/games/naev-data

USE_BZIP2=	yes
USE_DOS2UNIX=	conf.example
USE_GL=		gl
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_SDL=	sdl image mixer

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%DOCSDIR%%/conf.example
PLIST_DIRS=	%%DOCSDIR%%
.endif

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|%%DATADIR%%|${DATADIR}|g' -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -i "" -e 's|CFLAGS +=|CFLAGS ?=|g' ${WRKSRC}/build/Makefile.posix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/conf.example ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
