# Created by: ijliao
# $FreeBSD$

PORTNAME=	profxp
PORTVERSION=	3p2
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://duncanthrax.net/profxp/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/p/-pre/}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FXP (server-to-server FTP) client

RUN_DEPENDS=	p5-SOCKS>=0:${PORTSDIR}/net/p5-Socks \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	profxpv3.pl
perl_OLD_CMD=	/home/tom/ActivePerl-5.6/bin/perl

post-patch1:
	@${REINPLACE_CMD} -i '' '1s|^\#.*|#!${PERL}|' ${WRKSRC}/profxpv3.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/profxpv3.pl ${PREFIX}/bin/profxp
	${CP} -R ${WRKSRC}/profxp ${SITE_PERL}

.include <bsd.port.mk>
