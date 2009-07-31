# New ports collection makefile for:	mdh
# Date created:				12 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdh
PORTVERSION=	1.9.60
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gozer.org/programs/gtk/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2-based toolbar, like a smaller GNOME panel

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_GTOP)
CONFIGURE_ARGS+=	--disable-gtop
.else
LIB_DEPENDS+=	gtop-2.0:${PORTSDIR}/devel/libgtop
.endif

.if defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--disable-curl
.else
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| make| $$(MAKE)|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|\.\./lib/getopt/getopt\.c||g ; \
		 s|\.\./lib/getopt/getopt1\.c||g ; \
		 s|-I../lib/getopt||g ; \
		 s|$$(CC) -g|$$(CC)|g ; \
		 s|@INSTALL@ -m 0775|@INSTALL_PROGRAM@|g ; \
		 s|cp -p|@INSTALL_DATA@|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|"getopt\.h"|<getopt.h>|g' ${WRKSRC}/src/mdh.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
