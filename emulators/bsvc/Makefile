# New ports collection Makefile for:	bsvc
# Date created:		03-Mar-1997
# Whom:			tenser@spitfire.ecsel.psu.edu
#
# $FreeBSD$
#

PORTNAME=	bsvc
PORTVERSION=	2.1
CATEGORIES=	emulators tk82
MASTER_SITES=	ftp://ftp.redlinelabs.com/pub/bsvc/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/emulators
DISTFILES=	${DISTNAME}-src.tar.gz

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_REINPLACE=	yes

MAKE_ENV=	PROJECT_BASE=${PREFIX} WRKSRC=${WRKSRC}

pre-patch:
	${CP} ${WRKSRC}/Makefile.Linux ${WRKSRC}/Makefile
post-patch:
	${FIND} ${WRKSRC} -name "*.[ch]xx" -exec \
	  ${REINPLACE_CMD} -e 's/iostream\.h/iostream/; s/fstream\.h/fstream/' \{\} \;
	${FIND} ${WRKSRC} -name Makefile -exec \
	  ${REINPLACE_CMD} -e 's/make/$(MAKE)/' \{\} \;

.include <bsd.port.mk>
