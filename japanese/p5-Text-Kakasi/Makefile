# New ports collection makefile for:	p5-kakasi
# Version required:	1.01
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	Text-Kakasi-1.01
PKGNAME=	ja-p5-Text-Kakasi-1.01
CATEGORIES=	japanese perl5
MASTER_SITES=	http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=	knu@idaemons.org

LIB_DEPENDS=	kakasi.2:${PORTSDIR}/japanese/kakasi

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Text::Kakasi.3

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
