# New ports collection makefile for:	openal
# Date created:		25 September 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openal
PORTVERSION=	20040816
CATEGORIES=	audio
MASTER_SITES=	http://math.smsu.edu/~erik/files/fbsd/\
		http://www.smluc.org/~erik/files/fbsd/

MAINTAINER=	erik@smluc.org
COMMENT=	A 3D positional spatialized sound library

INFO=		openal

WRKSRC=		${WRKDIR}/${DISTNAME}/linux
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/-pthread/${PTHREAD_LIBS}/" ${WRKSRC}/configure

pre-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info
	@install-info ${PREFIX}/info/openal.info ${PREFIX}/info/dir

.include <bsd.port.mk>
