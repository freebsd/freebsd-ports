# New ports collection makefile for:	ksetiwatch
# Date created:				17 January 2001
# Whom:					Sverre Valgeirsson <sverre@k9k203-3.kam.afb.lu.se>
#
# $FreeBSD$

PORTNAME=	ksetiwatch
PORTVERSION=	2.6.1
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ksetiwatch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A monitoring tool for the seti@home client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/-1//}
USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
