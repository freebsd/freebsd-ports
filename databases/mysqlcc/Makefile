# New ports collection makefile for:	mysqlcc
# Date created:				03 April 2002
# Whom:					ferruccio.vitale@tin.it
#
# $FreeBSD$
#

PORTNAME=	mysqlcc
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	ftp://sunsite.dk/pub/databases/mysql/Downloads/MySQLCC/ \
		http://mysql.mirrors.pair.com/Downloads/MySQLCC/ \
		http://mirrors.sunsite.dk/mysql/Downloads/MySQLCC/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ferruccio.vitale@tin.it
COMMENT=	A platform-independent GUI administration client for the MySQL server

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_MYSQL=	yes
IGNORE_WITH_MYSQL=323

GNU_CONFIGURE=	yes
USE_QT_VER=	3
CONFIGURE_ARGS+=--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALABSE}/lib/mysql \
		--with-qt=${QT_PREFIX}

DOCS=	Changelog.txt README.txt TODO.txt
SHARE_DATA=	error.wav warning.wav syntax.txt

post-patch:
	${REINPLACE_CMD} -E -e 's@^(QMAKESPEC=)\$$QTDIR.*@\1${LOCALBASE}/share/qt/mkspecs/freebsd-g++@;s@\$$QTDIR/bin/qmake@${LOCALBASE}/bin/qmake@' ${WRKSRC}/configure
	${REINPLACE_CMD} -E -e "s@(QString mydir =) QDir.*@\1 \"${DATADIR}/\";@" ${WRKSRC}/src/CApplication.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${PREFIX}/bin/
	${MKDIR} -m 0755 -p ${DATADIR}/translations
.for f in ${SHARE_DATA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${DATADIR}/translations/
	${INSTALL_DATA} ${WRKSRC}/translations/*.ts ${DATADIR}/translations/
.if !defined(NOPORTDOCS)
	${MKDIR} -m 0755 -p ${DOCSDIR}/plugins
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	(umask 022; ${TAR} -C ${WRKSRC}/plugins -cpf - . | ${TAR} -C ${DOCSDIR}/plugins -xpf -)
.endif

.include <bsd.port.mk>
