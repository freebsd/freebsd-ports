# New ports collection makefile for:	pavuk
# Version required:			0.9pl11
# Date created:				19 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.4 1999/04/22 08:01:56 mharo Exp $
#

DISTNAME=		pavuk-0.9pl11
PKGNAME=		pavuk-0.9.11
CATEGORIES=		net www
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			ftp://ftp.idata.sk/pub/unix/www/
MASTER_SITE_SUBDIR=	apps/www/mirroring
EXTRACT_SUFX=		.tgz

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		Xpm.4:${PORTSDIR}/graphics/xpm

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
.for file in AUTHORS ChangeLog README THANK_TO TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/pavuk
.endfor
.endif

.include <bsd.port.mk>
