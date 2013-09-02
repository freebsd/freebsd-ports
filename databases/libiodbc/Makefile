# Created by: erikhb@bgnett.no
# $FreeBSD$

PORTNAME=	libiodbc
PORTVERSION=	3.52.8
CATEGORIES=	databases
MASTER_SITES=	SF/iodbc/iodbc/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	An ODBC 3.x driver manager, for universal data source access

LICENSE=		BSD LGPL20
LICENSE_COMB=		dual
LICENSE_FILE_BSD=	${WRKSRC}/LICENSE.BSD
LICENSE_FILE_LGPL20=	${WRKSRC}/LICENSE.LGPL

CONFLICTS=	unixODBC-[0-9]*

USES=		pathfix pkgconfig
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-iodbc-inidir=${ETCDIR}
USE_LDCONFIG=	yes

MAN1=		iodbc-config.1 iodbctest.1 iodbctestw.1

.if defined(WITH_GUI)
USE_GNOME+=	gtk20
MAN1+=		iodbcadm-gtk.1
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	GUI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|samples||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-ldl||g' ${WRKSRC}/admin/libiodbc.pc.in

post-install:
	@${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/odbc*.ini.sample ${ETCDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in Makefile.sample iodbctest.c
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
