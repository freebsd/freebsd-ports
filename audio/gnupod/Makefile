# New ports collection makefile for:	gnupod
# Date created: 			30 November 2002
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gnupod
PORTVERSION=	0.98
CATEGORIES=	audio perl5
MASTER_SITES=	http://savannah.gnu.org/download/gnupod/ \
		http://blinkenlights.ch/gnupod-dist/stable/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@dyn-ns.net
COMMENT=	Set of Perl scripts for using an Apple iPod

BUILD_DEPENDS=	${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String  \
		${SITE_PERL}/Getopt/Mixed.pm:${PORTSDIR}/devel/p5-Getopt-Mixed \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

INFO=		gnupod
MAN1=		gnupod_addsong.pl.1 gnupod_check.pl.1 gnupod_INIT.pl.1 \
		gnupod_otgsync.pl.1 gnupod_search.pl.1 mktunes.pl.1 \
		tunes2pod.pl.1
MANCOMPRESSED=	yes

USE_PERL5=	yes
HAS_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnupodrc.example ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnutunesdb.example ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnupod.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/mkspl.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnupod.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/fdl.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/version.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ipod.svg ${DOCSDIR}
.endif

.include <bsd.port.mk>
