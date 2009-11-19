# New ports collection makefile for:	backfract
# Date created:		8 August 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	backfract
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.igoweb.org/~wms/comp/backfract/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fractal image animated wallpaper program

USE_XORG=	x11
PLIST_FILES=	bin/backfract
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
NO_INSTALL_MANPAGE=	yes
ALL_TARGET= 	# none
MAKE_JOBS_UNSAFE=	yes

pre-configure:
	${PERL} -pi -e "s@-O3@${CFLAGS}@g" ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/backfract ${PREFIX}/bin

.include <bsd.port.mk>
