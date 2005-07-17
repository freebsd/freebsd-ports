# New ports collection makefile for:	fpdns
# Date Created:				July 2 2004
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	fpdns
PORTVERSION=	0.9.1
CATEGORIES=	dns
MASTER_SITES=	http://www.rfc.se/fpdns/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	edwin@mavetju.org
COMMENT=	FPDNS - Fingerprinting DNS servers

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_PERL5_RUN=	yes

MAN1=		fpdns.1

PLIST_FILES=	bin/fpdns

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"Requires at least Perl version 5.6.0"
.endif

pre-extract:
	@${MKDIR} ${WRKDIR}

post-patch:
	@${SED} -e 's#\\&\\fIperl\\fR\\|(1), \\fINet::DNS\\fR\\|(1)#&, http://www.rfc.se/fpdns/#' \
		${WRKDIR}/fpdns.1 > ${WRKDIR}/fpdns.1.sed
	@${MV} ${WRKDIR}/fpdns.1.sed ${WRKDIR}/fpdns.1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fpdns.pl ${PREFIX}/bin/fpdns
	${INSTALL_MAN} ${WRKDIR}/fpdns.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
