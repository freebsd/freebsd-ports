# ex:ts=8
# Ports collection makefile for:	jclassinfo
# Date created:			May 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jclassinfo
PORTVERSION=	0.19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows information about Java class, dependencies and more

USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
USE_GNOME=	pkgconfig gnomehack
USE_LIBTOOL_VER=15
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	jclassinfo.1

post-patch:
	@${REINPLACE_CMD} -e "s, docs,," ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
