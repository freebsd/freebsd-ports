# New ports collection makefile for:	Klira
# Date created:		Wed Dec 15 16:05:43 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klira
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A gstreamer based audio converter for KDE

DEPENDS=	${PORTSDIR}/misc/kdehier
LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USE_GSTREAMER=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

EXTRA_PATCHES= ${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure
#EXTRA_PATCHES=  ${PORTSDIR}/x11/kde3/files/extrapatch-old_configure

post-patch:
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E \
		-e 's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!'

.include <bsd.port.mk>
