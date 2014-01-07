# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	flwrap
PORTVERSION=	1.3.4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/flwrap/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Flwrap is a companion utility for fldigi

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

USES=		gmake dos2unix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|^CPPFLAGS|#CPPFLAGS|' \
		${WRKSRC}/src/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
