# New ports collection makefile for:	Oberon2C
# Date created:		December 3, 1997
# Whom:			Oliver Breuninger <ob@seicom.NET>
#
# $FreeBSD$

PORTNAME=	o2c
PORTVERSION=	1.16
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.uni-kl.de/pub/informatik/software/ \
		ftp://ftp.archive.de.uu.net/pub/programming/languages/oberon/www.uni-kl.de/OOC/files/misc/

MAINTAINER=	ob@seicom.NET

# does not support 64-bit platforms
ONLY_FOR_ARCHS=	i386

MAKE_ENV= 	MAKEOBJDIR=.
MAN1=	o2b.1 o2c.1 o2ef.1 o2whereis.1

post-extract:
	@${CP} ${FILESDIR}/o2 ${WRKSRC}

post-patch:
	@/usr/bin/perl -pi -e "s|\@PREFIX\@|${PREFIX}|g;" ${WRKSRC}/system/o2c.red.template

post-install:
	${INSTALL_DATA} ${WRKSRC}/system/o2c.red.template ${PREFIX}/lib/o2c-1.16
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
