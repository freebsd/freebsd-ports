# New ports collection makefile for: kile
# Date created:		21 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kile
PORTVERSION=	1.5.2
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=stable/apps/KDE3.x/office

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	A LaTeX source editor for KDE

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-extract:
	@${REINPLACE_CMD} -e 's|-pedantic ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
