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

.include <bsd.port.pre.mk>

RUN_DEPENDS=	${PERL_SITELIBDIR}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${PERL_SITELIBDIR}/Net/SOCKS.pm:${PORTSDIR}/net/p5-Socks \
		${PERL_SITELIBDIR}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${PERL_SITELIBDIR}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

# perl 5.6.0
.if ${OSVERSION} < 500007
RUN_DEPENDS+=	${PERL_SITELIBDIR}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor
.endif

USE_PERL5=	yes
PERL_SITELIBDIR=	${SITE_PERL}
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s,^#!.*,#!${PERL},g" ${WRKSRC}/profxpv3.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/profxpv3.pl ${PREFIX}/bin/profxp
	${CP} -R ${WRKSRC}/profxp ${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.include <bsd.port.post.mk>
