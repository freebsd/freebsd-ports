# Created by: ijliao
# $FreeBSD$

PORTNAME=	profxp
PORTVERSION=	3p2
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://duncanthrax.net/profxp/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/p/-pre/}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FXP (server-to-server FTP) client

RUN_DEPENDS=	p5-SOCKS>=0:net/p5-Socks \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Term-ReadLine-Perl>=0:devel/p5-Term-ReadLine-Perl

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	profxpv3.pl
perl_OLD_CMD=	/home/tom/ActivePerl-5.6/bin/perl

post-patch1:
	@${REINPLACE_CMD} -i '' '1s|^\#.*|#!${PERL}|' ${WRKSRC}/profxpv3.pl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/profxpv3.pl ${STAGEDIR}${PREFIX}/bin/profxp
	${CP} -R ${WRKSRC}/profxp ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

.include <bsd.port.mk>
