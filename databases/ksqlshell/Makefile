# New ports collection makefile for:	ksqlshell
# Date created:				Wed Aug 12 11:38:46 CEST 2005
# Whom:					Michael L. Hostbaek <mich@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ksqlshell
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	databases kde
MASTER_SITES=	http://www.ksqlshell.de/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	MySQL and PostgreSQL client for KDE

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_MYSQL=	yes
USE_PGSQL=	yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
