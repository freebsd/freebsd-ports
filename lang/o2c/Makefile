# New ports collection makefile for:	Oberon2C
# Version required:	1.16
# Date created:		December 3, 1997
# Whom:			Oliver Breuninger <ob@seicom.NET>
#
# $Id: Makefile,v 1.2 1998/06/16 12:06:13 asami Exp $

DISTNAME=	o2c-1.16
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.uni-kl.de/pub/informatik/software/ \
		ftp://cognac.informatik.uni-kl.de/pub/ooc/misc/

MAINTAINER=	ob@seicom.NET

MAKE_ENV= 	MAKEOBJDIR=.

MAN1=	o2b.1 o2c.1 o2ef.1 o2whereis.1

post-extract:
	@${CP} ${FILESDIR}/o2 ${WRKSRC}

post-patch:
	@/usr/bin/perl -pi -e "s|@PREFIX@|${PREFIX}|g;" ${WRKSRC}/system/o2c.red.template

post-install:
	${INSTALL_DATA} ${WRKSRC}/system/o2c.red.template ${PREFIX}/lib/o2c-1.16
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
