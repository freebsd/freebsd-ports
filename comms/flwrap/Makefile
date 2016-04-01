# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	flwrap
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/flwrap/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Flwrap is a companion utility for fldigi

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		gmake dos2unix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

OPTIONS_DEFINE=	DOCS

post-configure:
	@${REINPLACE_CMD} -e 's|^CPPFLAGS|#CPPFLAGS|' \
		${WRKSRC}/src/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
