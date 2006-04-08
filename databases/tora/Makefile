# New ports collection makefile for:	tora
# Date created:				03 January 2002
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	tora
PORTVERSION=	1.3.21
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Toolkit for Oracle

BUILD_DEPENDS=	${ORACLE_HOME}/lib/libclntsh.a:${PORTSDIR}/databases/oracle8-client
LIB_DEPENDS=	qscintilla.6:${PORTSDIR}/x11-toolkits/qscintilla
RUN_DEPENDS=	${ORACLE_HOME}/network/admin/tnsnames.ora:${PORTSDIR}/databases/oracle8-client

.if !defined(WITHOUT_MYSQL)
BUILD_DEPENDS+=	${X11BASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
RUN_DEPENDS+=	${X11BASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
.endif

.if !defined(WITHOUT_PGSQL)
BUILD_DEPENDS+=	${X11BASE}/lib/plugins/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt-pgsql-plugin
RUN_DEPENDS+=	${X11BASE}/lib/plugins/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt-pgsql-plugin
.endif

ORACLE_HOME?=	${LOCALBASE}/oracle8-client
ORACLE_VER=	8i	# Client version

USE_QT_VER=	3
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-oracle=${ORACLE_HOME} --with-oci-version=${ORACLE_VER:U}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.if defined(WITHOUT_KDE)
CONFIGURE_ARGS+=	--without-kde
.else
USE_KDELIBS_VER=3
.endif

PORTDOCS=	AUTHORS BUGS ChangeLog INSTALL NEWS README README.CODESTYLE README.LICENSE TODO

PREFIX2FIX=	help/preferences.html totool.cpp

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
# Just defining time_t as long in topiechart.h could be sufficient?
BROKEN=		does not compile with gcc 2.95
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/etc/torarc|${PREFIX}/etc/torarc|' ${PREFIX2FIX:S|^|${WRKSRC}/|}

post-install:
	${INSTALL_DATA} ${WRKSRC}/templates/* ${PREFIX}/lib/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
