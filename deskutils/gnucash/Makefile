# Ports collection makefile for:  gnucash
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	gnucash
PORTVERSION=	1.4.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gnucash.org/pub/gnucash/sources/stable/ \
		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnucash

MAINTAINER=     ade@FreeBSD.org

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/SWIG \
		g-wrap:${PORTSDIR}/devel/g-wrap \
		eperl:${PORTSDIR}/lang/eperl
LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore \
		guile.9:${PORTSDIR}/lang/guile
RUN_DEPENDS=	slib48:${PORTSDIR}/lang/slib \
		gnuplot:${PORTSDIR}/math/gnuplot \
		${site_perl}/HTML/Base.pm:${PORTSDIR}/www/p5-HTML \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww

site_perl=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
CONFIGURE_ENV=	MAKE=gmake \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"
CONFIGURE_ARGS=	--with-glib-config=${GLIB_CONFIG}
MAN1=		gnc-prices.1 gnucash.1


post-install:
	@strip ${PREFIX}/bin/gnucash
	@${LDCONFIG} -m ${PREFIX}/lib/gnucash/perl
	@cd ${LOCALBASE}/share/guile && ${LN} -sf ../slib .
	@${LOCALBASE}/bin/guile -c "(use-modules (ice-9 slib)) (require 'new-catalog)"

.include <bsd.port.mk>
