# New ports collection makefile for:	p5-GD1
# Date created:				June 26th 1997
# Whom:					James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GD
PORTVERSION=	1.41
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 interface to Gd Graphics Library

LIB_DEPENDS=	gd1.2:${PORTSDIR}/graphics/gd1

PERL_CONFIGURE=	yes
USE_REINPLACE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GD.3

post-patch:
	${REINPLACE_CMD} \
		-e 's,@@LOCALBASE@@,${LOCALBASE},g' \
		-e 's,@@X11BASE@@,${X11BASE},g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
