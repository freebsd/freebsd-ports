# New ports collection makefile for:	ifm
# Date created:				Mon Oct 12 12:32:07 EDT 1998
# Whom:					Dave Chapeskie <dchapes@ddm.on.ca>
#
# $FreeBSD$
#

PORTNAME=	ifm
PORTVERSION=	5.0
CATEGORIES=	games tk84
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/mapping-tools/ \
		ftp://www.plover.net/if-archive/mapping-tools/ \
		ftp://ftp.guetech.org/if-archive/mapping-tools/ \
		ftp://mirror.holmoak.co.uk/if-archive/mapping-tools/ \
		ftp://ftp.funet.fi/pub/misc/if-archive/mapping-tools/ \
		ftp://wuarchive.wustl.edu/doc/misc/if-archive/mapping-tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive Fiction mapper and walkthrough generator

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	WISH=${LOCALBASE}/bin/wish8.4

post-patch:
	@${PERL} -pi -e 's|lib doc progs|lib progs|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ifm.pdf ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/ifm/* ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
