# New ports collection makefile for:    nhppf-2.1
# Date created:         19 Apr 1997
# Whom:                 CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nhppf
PORTVERSION=	2.1
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/users/cjh/nhppf/

MAINTAINER=	cjh@FreeBSD.org

RUN_DEPENDS=    ${PREFIX}/share/texmf/fonts/type1/korean/pkmj/pkmjm0.pfb:$(PORTSDIR)/korean/hlatex-psfonts-wansung

NO_BUILD=	yes

USE_PERL5=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nhppf ${PREFIX}/bin/nhppf
	${MKDIR} ${PREFIX}/share/doc/nhppf
.for DOC in ChangeLog README charlist test.html
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/nhppf
.endfor

.include <bsd.port.mk>
