# New ports collection makefile for: allegrogl
# Date created:		22 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	allegrogl
PORTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	alleggl-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	OpenGL inteface for Allegro library

LIB_DEPENDS=	alleg.42:${PORTSDIR}/devel/allegro

USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_GL=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	makefile
ALL_TARGET=	lib
WRKSRC=		${WRKDIR}/alleggl

SHLIB_VER=	4
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"

post-extract:
	@${RM} ${WRKSRC}/gpl.txt

post-patch:
	@${REINPLACE_CMD} -e \
		's|^[[:blank:]]make |${GMAKE} |; \
		 s|\.so|&.${SHLIB_VER}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -Ee \
		's|@INSTALL@ ||; \
		 s|(@INSTALL_(DATA\|PROGRAM)@) -D|\1|; \
		 s|(CFLAGS) =|\1 +=|' \
		 ${WRKSRC}/make/makefile.unx

post-install:
	cd ${PREFIX}/lib && ${LN} -sf libagl.so.${SHLIB_VER} libagl.so
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examp/* ${EXAMPLESDIR}
	@${SED} -e \
		's|%%CC%%|${CC}|g; \
		 s|%%RM%%|${RM}|g; \
		 s|%%CFLAGS%%|${CFLAGS}|g; \
		 s|%%PREFIX%%|${PREFIX}|g; \
		 s|%%X11BASE%%|${X11BASE}|g; \
		 s|%%ALLEGRO_CONFIG%%|${ALLEGRO_CONFIG}|g' \
		 < ${FILESDIR}/makefile.ex > ${EXAMPLESDIR}/makefile

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
