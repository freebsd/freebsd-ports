# New ports collection makefile for:    Linuxdoc-SGML 1.6bh2
# Version required:     1.6bh2
# Date created:         2 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.5 1997/12/05 00:08:05 asami Exp $
#

DISTNAME=	linuxdoc-sgml-1.6bh2
PKGNAME=	ko-linuxdoc-sgml-1.6bh2
CATEGORIES=	korean textproc
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/util/tools/

MAINTAINER=	junker@jazz.snu.ac.kr

USE_PERL5=	yes
MAN1=		sgml2html.1 sgml2latex.1 sgml2rtf.1 sgmls.1 \
		sgml2info.1 sgml2lyx.1   sgml2txt.1 sgmlsasp.1
NO_BUILD=	yes

do-install:
	@cd ${WRKSRC}; \
	PREFIX=${PREFIX} ./install.quick

.include <bsd.port.mk>
