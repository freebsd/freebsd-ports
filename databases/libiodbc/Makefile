# New ports collection makefile for:	libiodbc
# Date created:				24 Mar 2000
# Whom:					erikhb@bgnett.no
#
# $FreeBSD$
#
# Note:  The location of ${INIDIR} and the installed name of the "odbctest"
#        binary were chosen such that this port does not conflict with
#        databases/unixODBC.

PORTNAME=	libiodbc
PORTVERSION=	3.52.6
CATEGORIES=	databases
MASTER_SITES=	http://www.iodbc.org/downloads/iODBC/ \
		SF/iodbc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ODBC 3.x driver manager, for universal data source access

CONFLICTS=	unixODBC-[0-9]*

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-iodbc-inidir=${INIDIR}
USE_LDCONFIG=	yes

MAN1=		iodbc-config.1 iodbctest.1 iodbctestw.1

CPPFLAGS=	${PTHREAD_CFLAGS} -D_BSD_WCHAR_T_DEFINED_
LDFLAGS=	${PTHREAD_LIBS}
INIDIR=		${PREFIX}/etc/${PORTNAME}

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
		's|$$CFLAGS -pthread|$$CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|samples||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-ldl||g' ${WRKSRC}/admin/libiodbc.pc.in

post-install:
	@${MKDIR} ${INIDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/odbc*.ini.sample ${INIDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for f in Makefile iodbctest.c
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
