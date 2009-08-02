# New ports collection makefile for:   kooldock
# Date created:        8 February 2007
# Whom:                Gustavo Perez
#
# $FreeBSD$
#

PORTNAME=		kooldock
PORTVERSION=		0.4.7
PORTREVISION=	2
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		OS-X dock-like for KDE

WRKSRC=			${WRKDIR}/kooldock

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:22
INSTALLS_ICONS=		yes
USE_GETTEXT=		yes
USE_KDELIBS_VER=	3
USE_BZIP2=		yes

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .

MANCOMPRESSED=		yes

.include <bsd.port.mk>
