# New ports collection makefile for:	GNU make
# Date created:		11 September 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	gmake381
PORTVERSION=	3.81
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	make
DISTNAME=	make-${PORTVERSION}

MAINTAINER=	autotools@FreeBSD.org
COMMENT=	GNU version of 'make' utility (3.81 legacy version)

IGNORE=		Internal infrastructure usage only.  Do _not_ use directly.

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-nls
PLIST_FILES=	bin/gmake381

.ifdef USE_GMAKE
.error You have `USE_GMAKE' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/make ${PREFIX}/bin/gmake381

.include <bsd.port.mk>
