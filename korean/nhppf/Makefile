# New ports collection makefile for:    nhppf-1.2
# Version required:     1.2
# Date created:         19 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.4 1998/09/15 21:31:46 asami Exp $
#

DISTNAME=	nhppf-1.2
PKGNAME=	ko-nhppf-1.2
CATEGORIES=	korean
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/util/nhppf/

MAINTAINER=	junker@jazz.snu.ac.kr

RUN_DEPENDS=    ${PREFIX}/share/fonts/HLaTeX-0.95-pfb:$(PORTSDIR)/korean/hlatexpsfonts

USE_PERL5=	yes
NO_BUILD=	yes

do-configure:
	@cd ${WRKSRC}; \
	${ECHO_MSG} "#!${PERL5}" > scriptheader; \
	${CAT} scriptheader nhppf > nhppf.new

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_SCRIPT} nhppf.new ${PREFIX}/bin/nhppf

.include <bsd.port.mk>
