# New ports collection makefile for:	fpdns
# Date Created:				July 2 2004
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	fpdns
PORTVERSION=	0.9.3
CATEGORIES=	dns net perl5
MASTER_SITES=	http://www.rfc.se/fpdns/distfiles/
DISTNAME=	Net-DNS-Fingerprint-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	FPDNS - Fingerprinting DNS servers

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS

PERL_CONFIGURE=	yes

MAN1=		fpdns.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Requires at least Perl version 5.6.0
.endif

file=	${WRKSRC}/blib/man1/fpdns.1
post-build:
	@${SED} -e 's#\\&\\fIperl\\fR\\|(1), \\fINet::DNS\\fR\\|(1)#&, http://www.rfc.se/fpdns/#' \
		${file} > ${file}.sed
	@${MV} ${file}.sed ${file}

post-install:
	${RM} ${SITE_PERL}/${PERL_ARCH}/auto/Net/DNS/Fingerprint/.packlist

.include <bsd.port.post.mk>
