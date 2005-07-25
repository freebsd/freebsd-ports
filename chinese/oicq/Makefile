# New ports collection makefile for:	oicq
# Date created:		10 Nov 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	oicq
PORTVERSION=	0.9
CATEGORIES=	chinese net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	perl-oicq
DISTNAME=	Net-OICQ-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implements OICQ messaging protocol

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor

PERL_CONFIGURE=	yes

MAN3=		Net::OICQ.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/q ${PREFIX}/bin

.include <bsd.port.post.mk>
