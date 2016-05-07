# Created by: anders
# $FreeBSD$

PORTNAME=	tora
PORTVERSION=	2.1.3
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for Oracle

LICENSE=	GPLv2

BUILD_DEPENDS=	cppunit-config:devel/cppunit
LIB_DEPENDS=	libqscintilla2.so:devel/qscintilla2 \
		libpcre.so:devel/pcre

OPTIONS_DEFINE=	PGSQL MYSQL DOCS
OPTIONS_DEFINE_i386=	ORACLE
OPTIONS_DEFAULT=	PGSQL MYSQL

USE_QT4=	corelib gui sql xml network moc_build uic_build rcc_build
USES=		autoreconf gmake libtool makeinfo
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PREFIX2FIX=	doc/help/preferences.texi doc/help/preferences.html

DOCS_USES=	makeinfo
DOCS_INFO=	tora

MYSQL_RUN_DEPENDS=	${QT_PLUGINDIR}/sqldrivers/libqsqlmysql.so:databases/qt4-mysql-plugin
PGSQL_RUN_DEPENDS=	${QT_PLUGINDIR}/sqldrivers/libqsqlpsql.so:databases/qt4-pgsql-plugin

ORACLE_HOME?=	${LOCALBASE}/oracle8-client
ORACLE_VER=	8i	# Client version

ORACLE_BUILD_DEPENDS=	${ORACLE_HOME}/lib/libclntsh.a:databases/oracle8-client
ORACLE_RUN_DEPENDS=	${ORACLE_HOME}/network/admin/tnsnames.ora:databases/oracle8-client
ORACLE_CONFIGURE_ON=	--with-oracle=${ORACLE_HOME} --with-oci-version=${ORACLE_VER:tu}

post-patch-DOCS-on:
	@${REINPLACE_CMD} 's|/etc/torarc|${PREFIX}/etc/torarc|' \
		${PREFIX2FIX:S|^|${WRKSRC}/|}

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|test doc|test|' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
