# New ports collection makefile for:   freetds
# Version required:	0.50
# Date created:		02 Nov 1999
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

DISTNAME=	freetds-0.50
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/freetds
EXTRACT_SUFX=	.tgz

MAINTAINER=	midom@dammit.lt

WRKSRC=		${WRKDIR}/freetds

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tdsver=7.0 \
		--enable-dbmfix
USE_GMAKE=	yes

.include <bsd.port.mk>
