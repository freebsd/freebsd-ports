# ex:ts=8
# New ports collection makefile for:	profxp
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	profxp
PORTVERSION=	3p2
CATEGORIES=	ftp
MASTER_SITES=	http://duncanthrax.net/profxp/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/p/-pre/}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FXP (server-to-server FTP) client

USE_PERL5=	yes

RUN_DEPENDS=	${PERL_SITELIBDIR}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${PERL_SITELIBDIR}/Net/SOCKS.pm:${PORTSDIR}/net/p5-Socks \
		${PERL_SITELIBDIR}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${PERL_SITELIBDIR}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

PERL_SITELIBDIR=	${SITE_PERL}
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s,^#!.*,#!${PERL},g" ${WRKSRC}/profxpv3.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/profxpv3.pl ${PREFIX}/bin/profxp
	${CP} -R ${WRKSRC}/profxp ${SITE_PERL}

.include <bsd.port.mk>
