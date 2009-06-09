# New ports collection makefile for:	vertex
# Date created:				1 June 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vertex
PORTVERSION=	0.1.15
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://wolfpack.twu.net/users/wolfpack/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D modeller for generating efficient game models

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_BZIP2=	yes
USE_GL=		yes
USE_GNOME=	imlib
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	UNIX

MAN1=		${PORTNAME}.1

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${REINPLACE_CMD} -e \
		's|make|$$(MAKE)|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|/usr/share/vertex|${DATADIR}|g' ${WRKSRC}/vertex/config.h
	@${REINPLACE_CMD} \
		-e 's|echo -n -e|printf|g' -e 's|--color=auto||' \
		${WRKSRC}/vertex/makefile_append.ini
	@${REINPLACE_CMD} -e \
		's|%%CC%%|${CC}|g ; \
		 s|%%CXX%%|${CXX}|g ; \
		 s|%%CXXFLAGS%%|${CXXFLAGS}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/vertex/platforms.ini
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/vertex/vmahelp.c
	@${REINPLACE_CMD} -e \
		's|CC =|CC ?=|g' ${WRKSRC}/pconf/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vertex/vertex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vertex/vertex.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/vertex/vertex.xpm ${DATADIR}/icons
	cd ${WRKSRC}/vertex/data && ${FIND} . -type f | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} a+x

.include <bsd.port.mk>
