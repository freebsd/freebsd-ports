# New ports collection makefile for:    nhppf-1.2
# Version required:     1.2
# Date created:         19 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.1.1.1 1997/06/04 09:06:45 asami Exp $
#

DISTNAME=	nhppf-1.2
PKGNAME=	kr-nhppf-1.2
CATEGORIES=	korean
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/util/nhppf/

MAINTAINER=	junker@jazz.snu.ac.kr

NO_BUILD=	yes

RUN_DEPENDS=    ${PREFIX}/share/fonts/HLaTeX-0.95-pfb:$(PORTSDIR)/korean/hlatexpsfonts \
		perl5.00401:${PORTSDIR}/lang/perl5

do-configure:
	@cd ${WRKSRC}; \
	${ECHO_MSG} "#!${PREFIX}/bin/perl5.003" > scriptheader; \
	${CAT} scriptheader nhppf > nhppf.new

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_SCRIPT} nhppf.new ${PREFIX}/bin/nhppf

.include <bsd.port.mk>
