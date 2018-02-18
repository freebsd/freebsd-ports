# Created by: anders
# $FreeBSD$

PORTNAME=	tora
PORTVERSION=	2.1.3
PORTREVISION=	12
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for Oracle

LICENSE=	GPLv2

BUILD_DEPENDS=	cppunit-config:devel/cppunit
LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2 \
		libpcre.so:devel/pcre

OPTIONS_DEFINE=	PGSQL MYSQL DOCS
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

post-patch-DOCS-on:
	@${REINPLACE_CMD} 's|/etc/torarc|${PREFIX}/etc/torarc|' \
		${PREFIX2FIX:S|^|${WRKSRC}/|}

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|test doc|test|' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
