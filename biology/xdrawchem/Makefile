# New ports collection makefile for:	xdrawchem
# Date created:				13 April 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	xdrawchem
PORTVERSION=	1.7.8
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xdrawchem
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Chemical drawing program

CFLAGS+=	-O0
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
QTCFGLIBS+=	${PTHREAD_LIBS}
QTCPPFLAGS+=	${PTHREAD_CFLAGS}
USE_GMAKE=	yes
USE_QT_VER=	3
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

pre-configure:
	${MKDIR} ${WRKDIR}
	${ECHO_CMD} \
	"Warning:  source code for this version has not been reviewed!" \
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} 
	@${ECHO_CMD} Waiting ten seconds--press control-C to cancel build.
	@sleep 10

post-patch:
	@${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g' ${WRKSRC}/xdrawchem/application_ob.cpp
	@${REINPLACE_CMD} -e \
		's|lround|(long int)rint|g' ${WRKSRC}/xdrawchem/*.cpp

.include <bsd.port.mk>
