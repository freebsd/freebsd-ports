# ex:ts=8
# New ports collection makefile for:	profxp
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	profxp
PORTVERSION=	3p1
CATEGORIES=	ftp
MASTER_SITES=	http://duncanthrax.net/profxp/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/p/-pre/}-src

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SOCKS.pm:${PORTSDIR}/net/p5-Socks \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

# perl 5.6.0
.if ${OSVERSION} < 500007
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s,^#!.*,#!${PERL},g" ${WRKSRC}/profxpv3.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/profxpv3.pl ${PREFIX}/bin/profxp
	${CP} -R ${WRKSRC}/profxp ${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.include <bsd.port.post.mk>
