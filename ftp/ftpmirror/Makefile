# New ports collection makefile for:	ftpmirror
# Version required:	1.96
# Date created:		10 January 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

DISTNAME=	ftpmirror-1.96
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.intec.co.jp/pub/utils/ftpmirror/beta/

MAINTAINER=	yasuf@big.or.jp

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
