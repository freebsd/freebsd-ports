# Created by: erikhb@bgnett.no
# $FreeBSD$

PORTNAME=	libiodbc
DISTVERSIONPREFIX=	v
DISTVERSION=	3.52.13
CATEGORIES=	databases

MAINTAINER=	kde@FreeBSD.org
COMMENT=	ODBC 3.x driver manager, for universal data source access

LICENSE=		BSD3CLAUSE LGPL20
LICENSE_COMB=		dual
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.BSD
LICENSE_FILE_LGPL20=	${WRKSRC}/LICENSE.LGPL

USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-iodbc-inidir=${ETCDIR} \
		--includedir=${LOCALBASE}/include/libiodbc \
		--disable-libodbc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	openlink
GH_PROJECT=	iODBC

OPTIONS_DEFINE=	GTK2 DOCS EXAMPLES
OPTIONS_SUB=	yes

GTK2_USE=	GNOME=cairo,gdkpixbuf2,gtk20
GTK2_USES=	gettext-runtime gnome
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2

GTK2_CONFIGURE_ENABLE=	gui

post-patch:
	@${REINPLACE_CMD} -e \
		's|-ldl||g' ${WRKSRC}/admin/libiodbc.pc.in

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
