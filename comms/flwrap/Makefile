# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	flwrap
PORTVERSION=	1.3.5
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Companion utility for fldigi

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		autoreconf gmake dos2unix

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
