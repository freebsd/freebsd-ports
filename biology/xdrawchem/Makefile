# New ports collection makefile for:	xdrawchem
# Date created:				13 April 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	xdrawchem
PORTVERSION=	1.7.3
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.prism.gatech.edu/~gte067k/xdrawchem/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Chemical drawing program

CFLAGS+=	-O0
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
QTCFGLIBS+=	${PTHREAD_LIBS}
QTCPPFLAGS+=	${PTHREAD_CFLAGS}
USE_GMAKE=	yes
USE_QT_VER=	3
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CPPFLAGS = -I/usr/X11R6/include|CPPFLAGS = @CPPFLAGS@|g ; \
		 s|^CXXFLAGS = -g|CXXFLAGS = @CXXFLAGS@|g' \
			${WRKSRC}/xdrawchem/Makefile.in
	@${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g' ${WRKSRC}/xdrawchem/application_ob.cpp
	@${REINPLACE_CMD} -e \
		's|lround|(long int)rint|g' ${WRKSRC}/xdrawchem/*.cpp

.include <bsd.port.mk>
