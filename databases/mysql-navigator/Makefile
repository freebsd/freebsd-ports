# New ports collection makefile for:	mysql-navigator
# Date created:				2 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-navigator
PORTVERSION=	1.3.12
CATEGORIES=	databases kde
MASTER_SITES=	http://ftp.kde.com/Database/MySQL_Navigator/ \
		http://sql.kldp.org/snapshots/ \
		ftp://sise15.mizi.com/pub/
DISTNAME=	mysqlnavigator-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_KDELIBS_VER=3
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql
CONFIGURE_ENV+=	MOC="${MOC}" QTDIR="${X11BASE}"
MAKE_ENV+=	MOC="${MOC}" QTDIR="${X11BASE}"

post-patch:
	@${REINPLACE_CMD} 's#-O2#$(CXXFLAGS)#g' ${WRKSRC}/configure

pre-configure:
	@${REINPLACE_CMD} "s#-lqt#-lqt-mt ${PTHREAD_LIBS}#g" \
		${WRKSRC}/src/main/Makefile.in

.include <bsd.port.mk>
