# New ports collection makefile for:	p5-Gimp
# Date created:				Dec 22 2000
# Whom:	      				vanilla@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Gimp
PORTVERSION=	1.211
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gimp
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/PDL.pm:${PORTSDIR}/math/PDL \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
LIB_DEPENDS=	gimp.2:${PORTSDIR}/graphics/gimp1
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lintl"

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		embedxpm.1 \
		scm2perl.1 \
		scm2scm.1 \
		xcftopnm.1
MAN3=		Gimp.3 \
		Gimp::Compat.3 \
		Gimp::Data.3 \
		Gimp::Feature.3 \
		Gimp::Fu.3 \
		Gimp::Lib.3 \
		Gimp::Module.3 \
		Gimp::Net.3 \
		Gimp::OO.3 \
		Gimp::PDL.3 \
		Gimp::Pixel.3 \
		Gimp::Pod.3 \
		Gimp::UI.3 \
		Gimp::Util.3 \
		Gimp::basewidget.3

.include <bsd.port.mk>
