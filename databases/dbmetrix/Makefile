# New ports collection makefile for:   dbmetrix
# Date created:                Tue Sep  5 15:30:00 PDT 2000
# Whom:                        Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	dbmetrix
PORTVERSION=	0.1.9
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.tamos.net/pub/dbMetrix/ \
		ftp://linux.gmu.edu/archive/dbMetrix/

MAINTAINER=	joseph@randomnetworks.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		mysqlclient.6:${PORTSDIR}/databases/mysql322-client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-mysql=${PREFIX} --prefix=${PREFIX}
CONFIGURE_ENV=	GTK_CONFIG=${GTK_CONFIG}

pre-configure:
	@${PERL} -pi -e "s.gtk-config.${GTK_CONFIG}.g" ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbmetrix ${PREFIX}/bin

.include <bsd.port.mk>
