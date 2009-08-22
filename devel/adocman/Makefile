# New ports collection makefile for:	adocman
# Date created:		4 January 2006
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	adocman
PORTVERSION=	0.13
CATEGORIES=	devel
MASTER_SITES=	SF/sitedocs/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated sourceforge administration tool

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey

PERL_CONFIGURE=	YES

SCRIPTS=	adocman atracker xml_export
DOCS=		LICENSE README TODO adocman.html xml_export.html

post-extract:
	@${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}

post-install:
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/$f ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
