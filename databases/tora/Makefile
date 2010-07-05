# New ports collection makefile for:	tora
# Date created:				03 January 2002
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	tora
DISTVERSION=	2.1.2
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	cm@therek.net
COMMENT=	Toolkit for Oracle

BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit
LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2 \
		pcre.0:${PORTSDIR}/devel/pcre

OPTIONS=	ORACLE "Build with Oracle support (i386 only)" off \
		PGSQL  "Build with PostgreSQL support" on \
		MYSQL  "Build with MySQL support" on

USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262 autoheader:262 libtool:22
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib sql xml network linguist moc_build uic_build rcc_build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PREFIX2FIX=	doc/help/preferences.texi doc/help/preferences.html

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
INFO=		tora
.endif

.if !defined(WITHOUT_MYSQL)
RUN_DEPENDS+=	${QT_PLUGINDIR}/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin
.endif

.if !defined(WITHOUT_PGSQL)
RUN_DEPENDS+=	${QT_PLUGINDIR}/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt4-pgsql-plugin
.endif

.if !defined(WITHOUT_ORACLE)
BUILD_DEPENDS+=	${ORACLE_HOME}/lib/libclntsh.a:${PORTSDIR}/databases/oracle8-client
RUN_DEPENDS+=	${ORACLE_HOME}/network/admin/tnsnames.ora:${PORTSDIR}/databases/oracle8-client

ORACLE_HOME?=	${LOCALBASE}/oracle8-client
ORACLE_VER=	8i	# Client version
CONFIGURE_ARGS+=	--with-oracle=${ORACLE_HOME} --with-oci-version=${ORACLE_VER:U}
.endif

run-autotools:
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./autogen.sh)

post-patch:
.if ${OSVERSION} < 700000
	${REINPLACE_CMD} -e 's|LIBS="|LIBS="-lpthread |' ${WRKSRC}/config/m4/qtkde.m4
.endif

pre-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|test doc|test|' ${WRKSRC}/Makefile.am
.else
	@${REINPLACE_CMD} -e 's|/etc/torarc|${PREFIX}/etc/torarc|'	\
		${PREFIX2FIX:S|^|${WRKSRC}/|}
.endif

.include <bsd.port.post.mk>
