# New ports collection makefile for:	edb
# Date created:		10/16/2000
# Whom:			Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	edb
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://people.tecnik93.com/~radim/tarballs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enlightenment Database Library

USE_LIBTOOL_VER=	13
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes

PLIST_FILES=	bin/edb_ed bin/edb_gtk_ed bin/edb_vt_ed bin/edb-config \
		include/Edb.h lib/libedb.a lib/libedb.la lib/libedb.so  \
		lib/libedb.so.1

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' ${WRKSRC}/configure \
		${WRKSRC}/tools/edb_gtk_ed/Makefile.in

.include <bsd.port.mk>
