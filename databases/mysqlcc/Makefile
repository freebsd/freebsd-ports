# New ports collection makefile for:	mysqlcc
# Date created:				03 April 2002
# Whom:					ferruccio.vitale@tin.it
#
# $FreeBSD$
#

PORTNAME=	mysqlcc
PORTVERSION=	0.9.3
CATEGORIES=	databases
MASTER_SITES=	ftp://sunsite.dk/pub/databases/mysql/Downloads/MySQLCC/ \
		http://mysql.mirrors.pair.com/Downloads/MySQLCC/ \
		http://mirrors.sunsite.dk/mysql/Downloads/MySQLCC/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ferruccio.vitale@tin.it
COMMENT=	A platform-independent GUI administration client for the MySQL server

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.10)
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.else
LIB_DEPENDS=	mysqlclient.12:${PORTSDIR}/databases/mysql40-client
.endif

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=	--with-qt=${X11BASE}

DOCS=	Changelog.txt README.txt TODO.txt

SHARE_DATA=	error.wav warning.wav syntax.txt

post-patch:
	${REINPLACE_CMD} -E -e 's@^(QMAKESPEC=\$$QTDIR).*@\1/share/qt/mkspecs/default@' ${WRKSRC}/configure
	${REINPLACE_CMD} -E -e 's@-pthread -D_THREAD_SAFE@${PTHREAD_CFLAGS}@;s@^(LFLAGS.*)-pthread@\1${PTHREAD_LIBS}@' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${PREFIX}/bin/
	${MKDIR} -m 0755 ${DATADIR}
.for f in ${SHARE_DATA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
