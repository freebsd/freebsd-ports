# New ports collection makefile for:   dbmetrix
# Date created:                Tue Sep  5 15:30:00 PDT 2000
# Whom:                        Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	dbmetrix
PORTVERSION=	0.1.9
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.tamos.net/pub/dbMetrix/ \
		ftp://ftp.upc.es/pub/linux/sunsite/X11/gtkbuffet/apps/dbmetrix/ \
		ftp://ftp.netsw.org/database/rdbms/mysql-addon/ \
		ftp://ftp.sai.msu.su/pub/unix/database/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Another GTK+ frontend for mysql

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PLIST_FILES=	bin/dbmetrix
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-mysql=${PREFIX}

pre-configure:
	@${REINPLACE_CMD} -e "s.gtk-config.${GTK_CONFIG}.g" ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbmetrix ${PREFIX}/bin

.include <bsd.port.mk>
