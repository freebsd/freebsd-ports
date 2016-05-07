# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdh
PORTVERSION=	1.9.60
PORTREVISION=	6
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gozer.org/programs/gtk/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2-based toolbar, like a smaller GNOME panel

LICENSE=	GPLv2+

USE_GNOME=	gtk20
USES=		gmake pkgconfig tar:bzip2
USE_XORG=	x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

OPTIONS_DEFINE=	CURL DOCS GTOP
OPTIONS_DEFAULT=	CURL GTOP

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=	--disable-curl

GTOP_LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop
GTOP_CONFIGURE_OFF=	--disable-gtop

post-patch:
	@${REINPLACE_CMD} -e 's| make| $$(MAKE)|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|\.\./lib/getopt/getopt\.c||g ; \
		 s|\.\./lib/getopt/getopt1\.c||g ; \
		 s|-I../lib/getopt||g ; \
		 s|$$(CC) -g|$$(CC)|g ; \
		 s|@INSTALL@ -m 0775|@INSTALL_PROGRAM@|g ; \
		 s|cp -p|@INSTALL_DATA@|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|"getopt\.h"|<getopt.h>|g' ${WRKSRC}/src/mdh.c
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/curl.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
