# New ports collection makefile for:	ftpmirror
# Version required:	1.95
# Date created:		10 January 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

DISTNAME=	ftpmirror-1.95
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.intec.co.jp/pub/utils/ftpmirror/alpha/

MAINTAINER=	yasuf@big.or.jp

USE_PERL5=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	PERL="${PERL}" INSTALL_PROGRAM="${INSTALL_SCRIPT}"

post-configure:
	perl -i.bak -pe 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Fan/Fan.pm
	perl -i.bak -pe 's,^#!.*$$,#!${PERL}, if $$. == 1' ${WRKSRC}/ftpmirror

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ftpmirror
	cd ${WRKSRC}; \
	  ${INSTALL_MAN} README.jis RELEASE.jis ${PREFIX}/share/doc/ftpmirror
.endif

.include <bsd.port.mk>
