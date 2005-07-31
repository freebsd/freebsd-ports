# New ports collection makefile for:	p5-Unix-Statgrab
# Date created:				June 20th, 2004
# Whom:					Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	Unix-Statgrab
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unix
PKGNAMEPREFIX=	p5-

MAINTAINER=	tim@bishnet.net
COMMENT=	Perl extension for collecting information about the machine

LIB_DEPENDS=	statgrab.7:${PORTSDIR}/devel/libstatgrab

USE_GNOME=	pkgconfig

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	INC="`pkg-config libstatgrab --cflags`" \
			LIBS="`pkg-config libstatgrab --libs`"

MAN3=		Unix::Statgrab.3

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500600
	@${PERL} -i -pe 's/}\(/}->(/' ${WRKSRC}/lib/Unix/Statgrab.pm
.endif
	@${RM} ${WRKSRC}/lib/Unix/Statgrab.pm.orig

.include <bsd.port.post.mk>
