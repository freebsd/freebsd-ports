# New ports collection makefile for:	p5-bsdconv
# Date created:				29 May 2009
# Whom:	      				buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	7.0
CATEGORIES=	converters perl5
MASTER_SITES=	https://github.com/buganini/perl-${PORTNAME}/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	p5-
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	bsdconv.7:${PORTSDIR}/converters/bsdconv

GITVERSION=	2c544e7
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-perl-${PORTNAME}-${GITVERSION}

PERL_CONFIGURE=	yes

MAN3=		bsdconv.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
