# ex:ts=8
# Ports collection makefile for:  g-wrap
# Date created:			  Jun 29, 2000
# Whom:				  Matthew Condell (mcondell@alum.mit.edu)
#
# $FreeBSD$
#

PORTNAME=	g-wrap
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	ftp://www.gnucash.org/pub/g-wrap/source/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	guile.6:${PORTSDIR}/lang/guile

INSTALLS_SHLIB=	yes

USE_GMAKE=	yes
USE_LIBTOOL=	yes

post-install:
	install-info --section "Scheme Programming" \
		--entry "* g-wrap: (g-wrap).      A tool for exporting C libraries into Scheme interpreters."\
		 ${PREFIX}/info/g-wrap.info ${PREFIX}/info/dir

.include <bsd.port.mk>
