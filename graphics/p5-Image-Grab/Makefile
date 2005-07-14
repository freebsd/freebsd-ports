# New ports collection makefile for:	Image-Grab
# Date created:				8 April 2001
# Whom:					Anatoliy Dmytriyev <tolid@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	Image-Grab
PORTVERSION=	1.4.2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	tolid@plab.ku.dk
COMMENT=	Perl extension for Grabbing images off the Internet

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTML/Tree.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	${ECHO_CMD} "N" |

MAN3=		Image::Grab.3

.include <bsd.port.mk>
