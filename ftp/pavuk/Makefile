# New ports collection makefile for:	pavuk
# Version required:			0.9pl3
# Date created:				19 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/12/16 22:37:40 billf Exp $
#

DISTNAME=		pavuk-0.9pl3
PKGNAME=		pavuk-0.9.3
CATEGORIES=		net www
MASTER_SITES=		ftp://ftp.idata.sk/pub/unix/www/ \
			ftp://ftp.max.irk.ru/pub/unix/net/www/wget/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/mirroring
EXTRACT_SUFX=		.tgz

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm.4:${PORTSDIR}/graphics/xpm \
			gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_XLIB=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

MAN1=			pavuk.1

do-install:

	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/pavuk ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/man/pavuk.1 ${PREFIX}/man/man1
	@ ${INSTALL_DATA} ${WRKSRC}/pavukrc.sample ${PREFIX}/etc
	@ ${INSTALL_DATA} ${WRKSRC}/pavuk_authinfo.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/pavuk
.for file in AUTHORS COPYING ChangeLog README THANK_TO TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/pavuk
.endfor
.endif

.include <bsd.port.mk>
