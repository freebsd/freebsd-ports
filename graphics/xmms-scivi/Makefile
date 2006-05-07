# New ports collection makefile for:	xmms-scivi
# Date created:				15 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	scivi
DISTVERSION=	0.2.0-rc3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Scivi is a visualization plugin for XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GL=		yes
USE_GNOME=	gtk12

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|<stdint.h>|<inttypes.h>|g" \
		${WRKSRC}/src/dynam.c ${WRKSRC}/src/glstuff.c \
		${WRKSRC}/src/gui.c ${WRKSRC}/src/plugin.c \
		${WRKSRC}/src/presets.c ${WRKSRC}/src/scivi.c \
		${WRKSRC}/src/utilx.c ${WRKSRC}/src/utilf.c \
		${WRKSRC}/src/utilsnd.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
