# New ports collection makefile for: kile
# Date created:		21 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kile
PORTVERSION=	1.7.1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	A LaTeX source editor for KDE

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-configure

USE_KDELIBS_VER=3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| syntax||g' ${WRKSRC}/kile/Makefile.in

.include <bsd.port.mk>
