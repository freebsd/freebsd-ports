# New ports collection makefile for:   generator
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	0.15
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82

CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tk8.2 -I${LOCALBASE}/include/tcl8.2"
CONFIGURE_ARGS=	--enable-tcltk

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

nakai:
	echo ${CONFIGURE_ARGS}

do-configure:
	( cd ${WRKSRC}/src; ${CONFIGURE_ENV} ../compile/${CONFIGURE_SCRIPT} \
	${CONFIGURE_ARGS} )

do-build:
	( cd ${WRKSRC}/src; ${GMAKE} )

do-install:
	${MKDIR} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/generator/
	${INSTALL_PROGRAM} ${WRKSRC}/src/generator-tcltk ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/share/* ${PREFIX}/share/generator

.include <bsd.port.mk>
