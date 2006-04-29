# New ports collection makefile for:    ktoblzcheck
# Date created:         25 November 2003
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktoblzcheck
PORTVERSION=	1.10
CATEGORIES=	finance german
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check bank codes of German banks

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_PYTHON=	2.3+
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes

MAN1=		ktoblzcheck.1

pre-configure:
	@${REINPLACE_CMD}=	-e 's,\$$LIBKTOBLZCHECK_CURRENT-LIBKTOBLZCHECK_AGE,\$$LIBKTOBLZCHECK_CURRENT-\$$LIBKTOBLZCHECK_AGE,' ${WRKSRC}/configure

.include <bsd.port.mk>
