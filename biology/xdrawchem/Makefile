# New ports collection makefile for:	xdrawchem
# Date created:				13 April 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	xdrawchem
PORTVERSION=	1.9.9
PORTREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	SF

MAINTAINER=	hemi@puresimplicity.net
COMMENT=	Chemical drawing program

LIB_DEPENDS=	openbabel.3:${PORTSDIR}/science/openbabel

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	3

CONFIGURE_ENV=	QTINCDIR="${LOCALBASE}/include" \
		QTLIBDIR="${LOCALBASE}/lib" \
		LDFLAGS="${LDFLAGS} -lm"

MAKE_ARGS+=	LDFLAGS+="-lqt-mt ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${ARCH}==sparc64
BROKEN=		does not compile on ${ARCH}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g' ${WRKSRC}/xdrawchem/application_ob.cpp
	@${REINPLACE_CMD} -e \
		's|lround|(long int)rint|g' ${WRKSRC}/xdrawchem/*.cpp

.include <bsd.port.post.mk>
