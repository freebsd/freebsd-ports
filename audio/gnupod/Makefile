# New ports collection makefile for:	gnupod
# Date created: 			30 November 2002
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gnupod
PORTVERSION=	0.25
CATEGORIES=	audio perl5
MASTER_SITES=	http://www.blinkenlights.ch/gnupod/
DISTNAME=	${PORTNAME}-tools-${PORTVERSION}

MAINTAINER=	david@dyn-ns.net

RUN_DEPENDS=    ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String  \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Copy.pm:${PORTSDIR}/devel/p5-File-Tools

USE_PERL5=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-tools

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gnupod_INITpod.pl ${PREFIX}/bin/gnupod_INITpod
	${INSTALL_SCRIPT} ${WRKSRC}/gnupod_addsong.pl ${PREFIX}/bin/gnupod_addsong
	${INSTALL_SCRIPT} ${WRKSRC}/gnupod_connect.pl ${PREFIX}/bin/gnupod_connect
	${INSTALL_SCRIPT} ${WRKSRC}/gnupod_delete.pl ${PREFIX}/bin/gnupod_delete
	${INSTALL_SCRIPT} ${WRKSRC}/mktunes.pl ${PREFIX}/bin/mktunes
	${INSTALL_SCRIPT} ${WRKSRC}/tunes2pod.pl ${PREFIX}/bin/tunes2pod

.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${CHMOD} 0755 ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/index-de.html ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/index.html ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/logo.png ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnutunesdb.example ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/doc/ipod.svg ${PREFIX}/share/doc/${PORTNAME}
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
