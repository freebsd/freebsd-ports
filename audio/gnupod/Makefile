# New ports collection makefile for:	gnupod
# Date created: 			30 November 2002
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gnupod
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnupod

MAINTAINER=	david@dyn-ns.net
COMMENT=	A set of Perl scripts for using an Apple iPod

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String  \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Getopt/Mixed.pm:${PORTSDIR}/devel/p5-Getopt-Mixed \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple

INFO=		gnupod

USE_PERL5=	yes
HAS_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnutunesdb.example ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnupod.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/gnupod.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/fdl.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/version.texi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ipod.svg ${DOCSDIR}
.endif

.include <bsd.port.mk>
