# ex:ts=8
# Ports collection makefile for:  gnucash
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	gnucash
PORTVERSION=	1.4.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	ftp://ftp.gnucash.org/pub/gnucash/gnucash/sources/stable/ \
		http://www.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnucash

MAINTAINER=     obrien@FreeBSD.org

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/SWIG \
		g-wrap:${PORTSDIR}/devel/g-wrap \
		eperl:${PORTSDIR}/lang/eperl
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.3:${PORTSDIR}/devel/glib12 \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		gnome.4:${PORTSDIR}/x11/gnomelibs \
		guile.6:${PORTSDIR}/lang/guile \
		xml.5:${PORTSDIR}/textproc/libxml
site_perl=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
RUN_DEPENDS=	slib48:${PORTSDIR}/lang/slib \
		gnuplot:${PORTSDIR}/math/gnuplot \
		${site_perl}/HTML/Base.pm:${PORTSDIR}/www/p5-HTML \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${site_perl}/URI.pm:${PORTSDIR}/net/p5-URI \
		${site_perl}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
#USE_X_PREFIX=	yes
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
	${LDCONFIG} -m ${PREFIX}/lib/
	${LDCONFIG} -m ${PREFIX}/lib/gnucash/perl
	cd ${LOCALBASE}/share/guile && ${LN} -sf ../slib .
	guile -c "(use-modules (ice-9 slib)) (require 'new-catalog)"

.include <bsd.port.mk>
