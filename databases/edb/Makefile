# New ports collection makefile for:	edb
# Date created:		10/16/2000
# Whom:			Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	edb
PORTVERSION=	1.0.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Enlightenment Database Library

USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' ${WRKSRC}/configure \
		${WRKSRC}/tools/edb_gtk_ed/Makefile.in

.include <bsd.port.mk>
