# New ports collection makefile for:	ifm
# Version required:			3.0
# Date created:				Mon Oct 12 12:32:07 EDT 1998
# Whom:					Dave Chapeskie <dchapes@ddm.on.ca>
#
# $FreeBSD$
#

DISTNAME=	ifm41
PKGNAME=	ifm-4.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.gmd.de/if-archive/mapping-tools/
MASTER_SITES=	ftp://ftp.gmd.de/if-archive/mapping-tools/ \
		ftp://wuarchive.wustl.edu/doc/misc/if-archive/mapping-tools/ \
		ftp://ftp.firedrake.org/if-archive/mapping-tools/ \
		ftp://ftp.funet.fi/pub/misc/if-archive/mapping-tools/ \
		ftp://mirror.aarnet.edu.au/pub/if-archive/mapping-tools/ \
		ftp://ftp.nodomainname.net/pub/mirrors/if-archive/mapping-tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dchapes@ddm.on.ca

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${LOCALBASE}/bin/wish8.2

post-install:
	install-info ${PREFIX}/info/ifm.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/scr2ifm.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/tkifm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
