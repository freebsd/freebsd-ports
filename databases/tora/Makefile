# Created by: anders
# $FreeBSD$

PORTNAME=	tora
PORTVERSION=	2.1.3
PORTREVISION=	15
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for Oracle

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	cppunit-config:devel/cppunit
LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2 \
		libpcre.so:devel/pcre

OPTIONS_DEFINE=	PGSQL MYSQL DOCS
OPTIONS_DEFAULT=	PGSQL MYSQL

USES=		autoreconf compiler:c++11-lang gmake libtool localbase:ldflags \
		makeinfo qmake:no_env qt:4
USE_QT=		corelib gui sql xml network moc_build qmake_build rcc_build uic_build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre=${LOCALBASE} \
		--with-qt-includes=${QT_INCDIR} \
		--with-qt-libraries=${QT_LIBDIR} \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

PREFIX2FIX=	doc/help/preferences.texi doc/help/preferences.html

DOCS_USES=	makeinfo
DOCS_INFO=	tora

MYSQL_USE=	QT=sql-mysql_run
PGSQL_USE=	QT=sql-pgsql_run

post-patch-DOCS-on:
	@${REINPLACE_CMD} 's|/etc/torarc|${PREFIX}/etc/torarc|' \
		${PREFIX2FIX:S|^|${WRKSRC}/|}

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|test doc|test|' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
