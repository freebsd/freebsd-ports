# New ports collection makefile for:    Linuxdoc-SGML 1.6bh2
# Date created:         2 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	linuxdoc-sgml
PORTVERSION=	1.6bh2
CATEGORIES=	korean textproc
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/users/cjh/sgml-tools-ko/old/

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Korean patch version of Linuxdoc-SGML

USE_PERL5=	yes
MAN1=		sgml2html.1 sgml2latex.1 sgml2rtf.1 sgmls.1 \
		sgml2info.1 sgml2lyx.1   sgml2txt.1 sgmlsasp.1
NO_BUILD=	yes

do-install:
	@cd ${WRKSRC}; \
	PREFIX=${PREFIX} ./install.quick

.include <bsd.port.mk>
