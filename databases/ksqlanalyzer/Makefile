# New ports collection makefile for:	ksqlanalyzer
# Date created:				Tue Sep 20 11:38:46 CEST 2005
# Whom:					Michael L. Hostbaek <mich@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ksqlanalyzer
PORTVERSION=	0.2.2
PORTREVISION=	4
CATEGORIES=	databases kde
MASTER_SITES=	http://www.kpage.de/download/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	MSSQL database client for KDE

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
