# Created by: Anatoliy Dmytriyev <tolid@plab.ku.dk>
# $FreeBSD$

PORTNAME=	Image-Grab
PORTVERSION=	1.4.2
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tolid@plab.ku.dk
COMMENT=	Perl extension for Grabbing images off the Internet

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	${ECHO_CMD} "N" |

MAN3=		Image::Grab.3

NO_STAGE=	yes
.include <bsd.port.mk>
