# New ports collection makefile for:	kmyirc
# Date created:		25 November 2002
# Whom:			Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$

PORTNAME=		kmyirc
PORTVERSION=		0.2.9
PORTREVISION=	11
CATEGORIES=		irc kde
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}-alpha/${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Easy to use IRC client for KDE

DEPRECATED=		Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_AUTOTOOLS=		libtool
USE_KDELIBS_VER=	3
USE_GMAKE=		yes

post-patch:
	${REINPLACE_CMD} -e "s,-O0,${CFLAGS},g;s,NOOPT_,,g; \
		s,-pedantic ,,g;s,-pedantic-errors,,g" ${WRKSRC}/configure
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e "s,NOOPT_,,g;s,FLAGS@,FLAGS@ -fPIC,"

.include <bsd.port.mk>
