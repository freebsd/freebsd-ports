PORTNAME=	libiodbc
DISTVERSION=	3.52.16
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/openlink/iODBC/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ODBC 3.x driver manager, for universal data source access
WWW=		https://www.iodbc.org/

LICENSE=		BSD3CLAUSE LGPL20
LICENSE_COMB=		dual
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.BSD
LICENSE_FILE_LGPL20=	${WRKSRC}/LICENSE.LGPL

USES=		libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-iodbc-inidir=${ETCDIR} \
		--includedir=${LOCALBASE}/include/libiodbc \
		--disable-libodbc

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GTK2 DOCS EXAMPLES
OPTIONS_SUB=	yes

GTK2_USE=	GNOME=cairo,gdkpixbuf,gtk20
GTK2_USES=	gettext-runtime gnome
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GTK2_CONFIGURE_ENABLE=	gui

post-install:
	@${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/odbc*.ini.sample ${STAGEDIR}/${ETCDIR}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for f in Makefile.sample iodbctest.c
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${STAGEDIR}/${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
