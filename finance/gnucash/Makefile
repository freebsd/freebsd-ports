# ex:ts=8
# Ports collection makefile for:  gnucash
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	gnucash
PORTVERSION=	1.3.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	ftp://www.gnucash.org/pub/gnucash/gnucash/sources/unstable/1.3.x/

MAINTAINER=     obrien@FreeBSD.org

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/SWIG \
		eperl:${PORTSDIR}/lang/eperl
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		guile.6:${PORTSDIR}/lang/guile
site_perl=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
RUN_DEPENDS=	slib48:${PORTSDIR}/lang/slib  \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${site_perl}/URI.pm:${PORTSDIR}/net/p5-URI  \
		${site_perl}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
ALL_TARGET=	gnome

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?= 	${LOCALBASE}/bin/glib12-config

CONFIGURE_ENV=	MAKE=gmake \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"
MAKE_ENV=	MAKE=gmake

post-configure:
	${PERL} -pi.orig -e 's:/usr/lib/gnucash:${PREFIX}/lib/gnucash:g'  \
		${WRKSRC}/src/quotes/gnc-prices

post-install:
	@strip ${PREFIX}/bin/gnucash.gnome
	${LDCONFIG} -m ${PREFIX}/lib/gnucash
	cd ${PREFIX}/share/guile && ln -sf ../slib .
	guile -c "(use-modules (ice-9 slib)) (require 'new-catalog)"

.include <bsd.port.mk>
