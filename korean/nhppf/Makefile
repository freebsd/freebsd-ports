# New ports collection makefile for:    nhppf-1.2
# Version required:     1.2
# Date created:         19 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.3 1997/09/22 16:22:12 max Exp $
#

DISTNAME=	nhppf-1.2
PKGNAME=	ko-nhppf-1.2
CATEGORIES=	korean
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/util/nhppf/

MAINTAINER=	junker@jazz.snu.ac.kr

NO_BUILD=	yes

RUN_DEPENDS=    ${PREFIX}/share/fonts/HLaTeX-0.95-pfb:$(PORTSDIR)/korean/hlatexpsfonts \
		perl5.00401:${PORTSDIR}/lang/perl5

do-configure:
	@cd ${WRKSRC}; \
	${ECHO_MSG} "#!${PERL5}" > scriptheader; \
	${CAT} scriptheader nhppf > nhppf.new

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_SCRIPT} nhppf.new ${PREFIX}/bin/nhppf

.include <bsd.port.mk>
