# New ports collection makefile for:	bfe
# Date created:		02 February 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	bfe
PORTVERSION=	2mar2001
CATEGORIES=	emulators
MASTER_SITES=	http://www.qzx.com/bfe/_download/

MAINTAINER=	greid@FreeBSD.org

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms
RUN_DEPENDS=	bochs:${PORTSDIR}/emulators/bochs

USE_X_PREFIX=	yes
USE_XPM=	yes

WRKSRC=		${WRKDIR}/bfe

pre-build:
	${PERL} -pi -e "s@/usr/X11R6@${X11BASE}@g; \
			s@/usr/local@${LOCALBASE}@g; \
			s@-lforms@-lforms -lXpm@g; \
			s@gcc@${CC}@g; s@-O2@${CFLAGS}@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bfe ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/share/bfe
	${INSTALL_DATA} ${WRKSRC}/README.bferc ${PREFIX}/share/bfe/bferc.sample
	${INSTALL_DATA} ${WRKSRC}/README.bferc ${PREFIX}/share/bfe

.include <bsd.port.mk>
