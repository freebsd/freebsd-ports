# New ports collection makefile for:	ftpmirror
# Date created:		10 January 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	ftpmirror
PORTVERSION=	1.96
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.intec.co.jp/pub/utils/ftpmirror/beta/

MAINTAINER=	yasuf@big.or.jp

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6

USE_PERL5=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	PERL="${PERL}" INSTALL_PROGRAM="${INSTALL_SCRIPT}"

post-configure:
	perl -i.bak -pe 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Fan/Fan.pm
.for f in ftpmirror rotate
	perl -i.bak -pe 's,^#!.*$$,#!${PERL}, if $$. == 1' ${WRKSRC}/${f}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ftpmirror
	cd ${WRKSRC}; \
	  ${INSTALL_MAN} README.jis RELEASE.jis ${PREFIX}/share/doc/ftpmirror
.endif

.include <bsd.port.mk>
