# New ports collection makefile for: escpf
# Version required:	0.4beta2
# Date created:		15 June 1996
# Whom:			Mita Yoshio <mita@iis.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/12/19 03:33:09 max Exp $
#

DISTNAME=	escpf-0.4beta2
PKGNAME=	ja-escpf-0.4b2
CATEGORIES=	japanese print
MASTER_SITES=	http://www.bekkoame.or.jp/~wing/Linux/Escpf/

MAINTAINER=	mita@jp.FreeBSD.org

DOCDIR=		${PREFIX}/share/doc/escpf

post-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/escpf.doc ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/escpf.euc ${DOCDIR}

.include <bsd.port.mk>
