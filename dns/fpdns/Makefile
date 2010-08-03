# New ports collection makefile for:	fpdns
# Date Created:				July 2 2004
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	fpdns
PORTVERSION=	0.9.3
CATEGORIES=	dns net perl5
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://dougbarton.us/Downloads/
DISTNAME=	Net-DNS-Fingerprint-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	FPDNS - Fingerprinting DNS servers

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS

PERL_CONFIGURE=	yes

MAN1=		fpdns.1

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

file=	${WRKSRC}/blib/man1/fpdns.1
post-build:
	@${SED} -e 's#\\&\\fIperl\\fR\\|(1), \\fINet::DNS\\fR\\|(1)#&, http://www.rfc.se/fpdns/#' \
		${file} > ${file}.sed
	@${MV} ${file}.sed ${file}

post-install:
	${RM} ${SITE_PERL}/${PERL_ARCH}/auto/Net/DNS/Fingerprint/.packlist

.include <bsd.port.mk>
