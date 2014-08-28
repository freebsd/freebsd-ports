# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	ultragetopt
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://kevinlocke.name/programs/ ${MASTER_SITE_LOCAL}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Versatile and customizable implementation of getopt()

LICENSE=	MIT

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	PREFIX="${PREFIX}"
USES=		gmake libtool
USE_LDCONFIG=	yes

PLIST_FILES=	include/ultragetopt.h \
		lib/libultragetopt.a lib/libultragetopt.so \
		lib/libultragetopt.so.0 lib/libultragetopt.so.0.0.0

.include <bsd.port.mk>
