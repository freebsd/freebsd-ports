# New ports collection makefile for:	ifm
# Date created:				Mon Oct 12 12:32:07 EDT 1998
# Whom:					Dave Chapeskie <dchapes@ddm.on.ca>
#
# $FreeBSD$
#

PORTNAME=	ifm
PORTVERSION=	4.1
PORTREVISION=	2
CATEGORIES=	games tk84
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/mapping-tools/ \
		ftp://www.plover.net/if-archive/mapping-tools/ \
		ftp://ftp.guetech.org/if-archive/mapping-tools/ \
		ftp://mirror.holmoak.co.uk/if-archive/mapping-tools/ \
		ftp://ftp.funet.fi/pub/misc/if-archive/mapping-tools/ \
		ftp://wuarchive.wustl.edu/doc/misc/if-archive/mapping-tools/
DISTFILES=	ifm41.tgz

MAINTAINER=	bsdport@ddm.wox.org
COMMENT=	Interactive Fiction mapper and walkthrough generator

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${LOCALBASE}/bin/wish8.4

post-install:
	install-info ${PREFIX}/info/ifm.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/scr2ifm.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/tkifm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
