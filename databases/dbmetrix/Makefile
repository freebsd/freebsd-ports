# New ports collection makefile for:   dbmetrix
# Date created:                Tue Sep  5 15:30:00 PDT 2000
# Whom:                        Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	dbmetrix
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.tamos.net/pub/dbMetrix/ \
		ftp://linux.gmu.edu/archive/dbMetrix/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Another GTK+ frontend for mysql

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-mysql=${PREFIX}

pre-configure:
	@${REINPLACE_CMD} -e "s.gtk-config.${GTK_CONFIG}.g" ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbmetrix ${PREFIX}/bin

.include <bsd.port.mk>
