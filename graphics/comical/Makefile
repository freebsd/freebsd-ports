# Created by: John McAree <john@mcaree.org>
# $FreeBSD$

PORTNAME=	comical
PORTVERSION=	0.8
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sequential image viewer

LIB_DEPENDS=	libunrar.so:archivers/libunrar

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_UNSAFE=	yes

USES=		gmake
USE_WX=		2.6+
WX_PREMK=	yes
WX_UNICODE=	yes
PLIST_FILES=	bin/comical

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|\`wx-config --cxx\`|${CXX}|; \
		s|wx-config|${WX_CONFIG}|; \
		s|unrar/libunrar.a u|u|; \
		s|-lunrar|-L${LOCALBASE}/lib -lunrar|;' \
		${WRKSRC}/Makefile

	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|; \
		s|-D_UNIX|-D_UNIX -DwxUSE_UNICODE|; \
		s|CFLAGS =|CFLAGS=${CFLAGS} |; \
		s|CPPFLAGS =|CPPFLAGS=${CXXFLAGS} |; \
		s|$$(CC)|${CXX}|; \
		s|-I../unrar|-I${LOCALBASE}/include/libunrar3|;' \
		${WRKSRC}/src/Makefile

	${REINPLACE_CMD} -e 's|gcc|${CC}|; \
		s|CFLAGS=|CFLAGS+=|;' \
		${WRKSRC}/unzip/Makefile

.if ${WX_VERSION} == "2.8"
	${REINPLACE_CMD} -e 's|frame->SetIcon|//frame->SetIcon|' \
		${WRKSRC}/src/ComicalApp.cpp
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
