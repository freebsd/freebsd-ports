# New ports collection makefile for:	edb
# Date created:		10/16/2000
# Whom:			Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	edb
PORTVERSION=	1.0.3
CATEGORIES=	databases
MASTER_SITES=	http://www.ny.us.rasterman.com/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ishmael27@home.com

USE_LIBTOOL=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's|gtk-config|${GTK_CONFIG}|g' ${WRKSRC}/configure \
		${WRKSRC}/tools/edb_gtk_ed/Makefile.in

.include <bsd.port.mk>
