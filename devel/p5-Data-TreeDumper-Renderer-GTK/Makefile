# New ports collection makefile for:	p5-Data-TreeDumper-Renderer-GTK
# Date Created:				21 Apr 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-TreeDumper-Renderer-GTK
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GTK renderer for Data::TreeDumper

BUILD_DEPENDS=	${SITE_PERL}/Data/TreeDumper.pm:${PORTSDIR}/devel/p5-Data-TreeDumper \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN3=		Data::TreeDumper::Renderer::GTK.3

.include <bsd.port.mk>
