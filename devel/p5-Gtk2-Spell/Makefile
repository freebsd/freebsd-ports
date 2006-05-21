# New ports collection makefile for:	p5-Gtk2-Spell
# Date created:		2006-03-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	Gtk2-Spell
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Perl interface to the Gtk2Spell library

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2

PERL_CONFIGURE=	yes

MAN3=	Gtk2::Spell.3

.include <bsd.port.mk>
