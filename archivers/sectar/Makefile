# New ports collection makefile for:   sectar
# Date created:        22 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		sectar
PORTVERSION=		1.01
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	star

MAINTAINER=		greid@ukug.uk.freebsd.org

LIB_DEPENDS=		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib -lgnugetopt"
USE_LIBTOOL=		yes

.include <bsd.port.mk>
