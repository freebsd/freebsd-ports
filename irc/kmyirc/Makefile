# New ports collection makefile for:	kmyirc
# Date created:		25 November 2002
# Whom:			Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$

PORTNAME=		kmyirc
PORTVERSION=		0.2.9
PORTREVISION=		5
CATEGORIES=		irc kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		laszlof@vonostingroup.com
COMMENT=		Easy to use IRC client for KDE

USE_AUTOTOOLS=		libtool:15
USE_KDELIBS_VER=	3
USE_GMAKE=		yes

post-patch:
	${REINPLACE_CMD} -e "s,-O0,${CFLAGS},g;s,NOOPT_,,g; \
		s,-pedantic ,,g;s,-pedantic-errors,,g" ${WRKSRC}/configure
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e "s,NOOPT_,,g;s,FLAGS@,FLAGS@ -fPIC,"

.include <bsd.port.mk>
