# New ports collection makefile for:	openal
# Date created:		25 September 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openal
PORTVERSION=	20020712fbsd
CATEGORIES=	audio
MASTER_SITES=	http://math.smsu.edu/~erik/files/fbsd/\
		http://smluc.org/~erik/\
		http://csc.smsu.edu/~greenwald/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}/linux
GNU_CONFIGURE=  yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info
	install-info ${PREFIX}/info/openal.info ${PREFIX}/info/dir

.include <bsd.port.mk>
