# New ports collection makefile for:	Shout
# Date created:				18 April 2001
# Whom:					leo
#
# $FreeBSD$
#

PORTNAME=	Shout
PORTVERSION=	1.0
CATEGORIES=	audio perl5
MASTER_SITES=	# http://www.icecast.org/files/libshout/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl glue for libshout MP3 streaming source library

LIB_DEPENDS=	shout.2:${PORTSDIR}/audio/libshout

PERL_CONFIGURE=	yes

MAN3=		Shout.3

pre-configure:
	${MKDIR} ${WRKSRC}/examples
	${MV} ${WRKSRC}/example.pl ${WRKSRC}/example2.pl ${WRKSRC}/examples

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* \
		${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

.include <bsd.port.mk>
