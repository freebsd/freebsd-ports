# New ports collection makefile for:	ifm
# Date created:				Mon Oct 12 12:32:07 EDT 1998
# Whom:					Dave Chapeskie <dchapes@ddm.on.ca>
#
# $FreeBSD$
#

PORTNAME=	ifm
PORTVERSION=	4.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.gmd.de/if-archive/mapping-tools/
MASTER_SITES=	ftp://ftp.gmd.de/if-archive/mapping-tools/ \
		ftp://wuarchive.wustl.edu/doc/misc/if-archive/mapping-tools/ \
		ftp://ftp.firedrake.org/if-archive/mapping-tools/ \
		ftp://ftp.funet.fi/pub/misc/if-archive/mapping-tools/ \
		ftp://mirror.aarnet.edu.au/pub/if-archive/mapping-tools/ \
		ftp://ftp.nodomainname.net/pub/mirrors/if-archive/mapping-tools/
DISTFILES=	ifm41.tgz

MAINTAINER=	dchapes@ddm.on.ca

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${LOCALBASE}/bin/wish8.2

post-install:
	install-info ${PREFIX}/info/ifm.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/scr2ifm.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/tkifm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
