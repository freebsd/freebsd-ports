# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	gmcal
PORTVERSION=	0.0.1
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	SF/libmcal/${PORTNAME}/${PORTVERSION}

MAINTAINER=	thierry@pompo.net
COMMENT=	GMCAL is a GTK+ frontend for the libmcal package

DEPRECATED=	Depends on expired misc/libmcal
EXPIRATION_DATE=2014-02-01

LIB_DEPENDS=	libmcal.so:${PORTSDIR}/misc/libmcal
RUN_DEPENDS=	${LOCALBASE}/mcal/mcal:${PORTSDIR}/deskutils/mcal

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/gmcal
USE_GNOME=	gtk12

NO_STAGE=	yes
post-extract:
	${CHMOD} a-x ${WRKSRC}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmcal ${PREFIX}/bin

post-install:
	@${ECHO} "*****************************************************************************"
	@${ECHO} ""
	@${ECHO} " gmcal has been installed as ${PREFIX}/bin/gmcal."
	@${ECHO} ""
	@${ECHO} "*****************************************************************************"

.include <bsd.port.mk>
