# New ports collection makefile for:	KDE PIM
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdepim
PORTVERSION=	2.2
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src

MAINTAINER=	demon@FreeBSD.org

USE_KDELIBS_VER=2
USE_BISON=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

pre-configure:
	find ${WRKSRC}/libical -name Makefile.in | xargs ${PERL} -pi -e \
		"s|INSTALL = \@INSTALL\@|INSTALL=${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP}|g"

.include <bsd.port.mk>
