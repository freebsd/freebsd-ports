# Ports collection makefile for:  gnucash
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	gnucash
PORTVERSION=	1.4.11
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gnucash.org/pub/gnucash/sources/stable/ \
		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnucash

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/SWIG \
		g-wrap:${PORTSDIR}/devel/g-wrap \
		eperl:${PORTSDIR}/lang/eperl
LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${LOCALBASE}/share/slib/Template.scm:${PORTSDIR}/lang/slib \
		gnuplot:${PORTSDIR}/math/gnuplot \
		${site_perl}/HTML/Base.pm:${PORTSDIR}/www/p5-HTML \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww

site_perl=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_PERL5=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-glib-config=${GLIB_CONFIG}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		gnc-prices.1 gnucash.1

pre-patch:
	@${PERL} -pi -e 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's^\$\{datadir\}/gnome/^\$\(datadir\)/^g ; \
		 s^\$\{datadir\}/aclocal^\$\(prefix\)/share/aclocal^g ; \
		 s^\$\{datadir\}/locale^\$\(prefix\)/share/locale^g'

post-install:
	@strip ${PREFIX}/bin/gnucash
	@${LDCONFIG} -m ${PREFIX}/lib/gnucash/perl
	@cd ${LOCALBASE}/share/guile && ${LN} -sf ../slib .
	@${LOCALBASE}/bin/guile -c "(use-modules (ice-9 slib)) (require 'new-catalog)"

.include <bsd.port.mk>
