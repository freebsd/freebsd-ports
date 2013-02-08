# Created by: anders
# $FreeBSD$

PORTNAME=	tora
PORTVERSION=	2.1.3
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for Oracle

BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit
LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2 \
		pcre.3:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	PGSQL MYSQL DOCS
OPTIONS_DEFINE_i386=	ORACLE
OPTIONS_DEFAULT=	PGSQL MYSQL

USE_AUTOTOOLS=	aclocal automake autoconf autoheader libtool
USE_QT4=	gui corelib sql xml network linguist moc_build uic_build rcc_build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PREFIX2FIX=	doc/help/preferences.texi doc/help/preferences.html

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INFO=		tora
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${QT_PLUGINDIR}/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${QT_PLUGINDIR}/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt4-pgsql-plugin
.endif

.if ${PORT_OPTIONS:MORACLE}
BUILD_DEPENDS+=	${ORACLE_HOME}/lib/libclntsh.a:${PORTSDIR}/databases/oracle8-client
RUN_DEPENDS+=	${ORACLE_HOME}/network/admin/tnsnames.ora:${PORTSDIR}/databases/oracle8-client

ORACLE_HOME?=	${LOCALBASE}/oracle8-client
ORACLE_VER=	8i	# Client version
CONFIGURE_ARGS+=	--with-oracle=${ORACLE_HOME} --with-oci-version=${ORACLE_VER:U}
.endif

run-autotools:
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./autogen.sh)

pre-configure:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|/etc/torarc|${PREFIX}/etc/torarc|'	\
		${PREFIX2FIX:S|^|${WRKSRC}/|}
.else
	@${REINPLACE_CMD} -e 's|test doc|test|' ${WRKSRC}/Makefile.am
.endif

.include <bsd.port.mk>
