# New ports collection makefile for:	gmcal
# Date created:		Mon Oct 15 09:09:46 GMT 2001
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	gmcal
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libmcal

MAINTAINER=	thierry@pompo.net
COMMENT=	GMCAL is a GTK+ frontend for the libmcal package

LIB_DEPENDS=	mcal.0:${PORTSDIR}/misc/libmcal
RUN_DEPENDS=	${LOCALBASE}/mcal/mcal:${PORTSDIR}/deskutils/mcal

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/gmcal
USE_GNOME=	gtk12

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
