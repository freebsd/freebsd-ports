# New ports collection makefile for:	mysql-navigator
# Date created:				2 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-navigator
PORTVERSION=	1.3.3.6
CATEGORIES=	databases kde
MASTER_SITES=	http://sql.kldp.org/snapshots/ \
		ftp://sise15.mizi.com/pub/
DISTNAME=	mysqlnavigator-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_KDELIBS_VER=2
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql

post-patch:
	@ ${PERL} -pi -e 's#-O2#$(CXXFLAGS)#g' ${WRKSRC}/configure

.include <bsd.port.mk>
