# New ports collection makefile for:	gnupod
# Date created: 			30 November 2002
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gnupod
PORTVERSION=	0.26
CATEGORIES=	audio perl5
MASTER_SITES=	http://www.blinkenlights.ch/gnupod/
DISTNAME=	${PORTNAME}-tools-${PORTVERSION}

MAINTAINER=	david@dyn-ns.net

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String  \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Copy.pm:${PORTSDIR}/devel/p5-File-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Getopt/Mixed.pm:${PORTSDIR}/devel/p5-Getopt-Mixed \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple

USE_PERL5=	yes
HAS_CONFIGURE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-tools

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${CHMOD} 0755 ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/logo.png ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnutunesdb.example ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/ipod.svg ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
