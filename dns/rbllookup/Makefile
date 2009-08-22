# New ports collection makefile for:	rbllookup
# Date created:		2004-07-14
# Whom:			Marcin Gondek <drixter@e-utp.net>
#
# $FreeBSD$
#

PORTNAME=	rbllookup
PORTVERSION=	0.0.1.1
CATEGORIES=	dns mail
MASTER_SITES=	SF

MAINTAINER=	drixter@e-utp.net
COMMENT=	Check given IP/Host presence in 106 RBLs

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor

NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/rbllookup
PORTDOCS=	CHANGELOG INSTALL NOTES README TODO gpg.asc

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rbl.pl ${PREFIX}/bin/rbllookup
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
