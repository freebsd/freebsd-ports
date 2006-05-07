# New ports collection makefile for:   cgoban
# Date created:        28 October 1996
# Whom:                simonm@dcs.gla.ac.uk
#
# $FreeBSD$
#

PORTNAME=	cgoban
PORTVERSION=	1.9.14
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cgoban1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet Go Server client and game editor

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:253
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN6=		cgoban.6
PLIST_FILES=	bin/cgoban

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/gnugo|${LOCALBASE}/bin/gnugo|' ${WRKSRC}/src/cgoban.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cgoban ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man6/cgoban.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
