# New ports collection makefile for: allegrogl
# Date created:		22 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	allegrogl
PORTVERSION=	0.4.3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/AllegroGL%20source/${PORTVERSION}
DISTNAME=	alleggl-${PORTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	OpenGL interface for Allegro library

LIB_DEPENDS=	alleg.42:${PORTSDIR}/devel/allegro

CONFLICTS=	allegro-devel-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		glu
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	makefile
ALL_TARGET=	lib
WRKSRC=		${WRKDIR}/alleggl

post-extract:
	@${RM} ${WRKSRC}/gpl.txt

post-patch:
	@${REINPLACE_CMD} -e 's|^[[:blank:]]make |${GMAKE} |' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examp/* ${EXAMPLESDIR}
	@${SED} -e \
		's|%%CC%%|${CC}|g; \
		 s|%%RM%%|${RM}|g; \
		 s|%%CFLAGS%%|${CFLAGS}|g; \
		 s|%%PREFIX%%|${PREFIX}|g; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g; \
		 s|%%ALLEGRO_CONFIG%%|${ALLEGRO_CONFIG}|g' \
		 < ${FILESDIR}/makefile.ex > ${EXAMPLESDIR}/makefile

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
