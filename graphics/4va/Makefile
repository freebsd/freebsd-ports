# New ports collection makefile for:	4va
# Date created:		26 July 1998
# Whom:			Malte Lance <malte.lance@gmx.net>
#
# $FreeBSD$
#

PORTNAME=		4va
PORTVERSION=		1.21
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/hacks/X
EXTRACT_SUFX=		.tgz

MAINTAINER=	malte.lance@gmx.net

USE_XLIB=	yes
MAN1=		4va.1

4VA_REL_DATA_DIR=	share/4va-1.21
4VA_DATA_FILES=		16cell.4vd 24cell.4vd 5cell.4vd 600cell.4vd ctor.4vd \
			ctor2.4vd hcube.4vd hsph.4vd sin.4vd tripris.4vd

post-extract:
	@${CHMOD} -R go-x ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/4va ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/4vdmake ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ctorus ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cutctorus ${PREFIX}/bin
	${MKDIR} ${PREFIX}/${4VA_REL_DATA_DIR}
	for i in ${4VA_DATA_FILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${4VA_REL_DATA_DIR}; \
	done
	${INSTALL_MAN} ${WRKSRC}/4va.man ${PREFIX}/man/man1/4va.1

.include <bsd.port.mk>
