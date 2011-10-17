# New ports collection makefile for:	p5-Glib-Object-Introspection
# Date created:		2011-10-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Glib-Object-Introspection
PORTVERSION=	0.003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dynamically create Perl language bindings

BUILD_DEPENDS=	gobject-introspection>=0.10.0:${PORTSDIR}/devel/gobject-introspection \
		p5-ExtUtils-Depends>=0.300:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.240:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	gobject-introspection>=0.10.0:${PORTSDIR}/devel/gobject-introspection \
		p5-Glib2>=1.240:${PORTSDIR}/devel/p5-Glib2

PERL_CONFIGURE=	yes

MAN3=		Glib::Object::Introspection.3

post-patch:
	@${REINPLACE_CMD} -e 's|gcc -shared -g|& -fPIC|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
