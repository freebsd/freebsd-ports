# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Devel-LeakTrace
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Indicate where leaked variables are coming from

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		gnome perl5 pkgconfig
USE_GNOME=	glib20
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/LeakTrace/LeakTrace.so

.include <bsd.port.mk>
