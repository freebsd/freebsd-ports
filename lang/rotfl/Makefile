# ex:ts=8
# New ports collection makefile for:	rotfl
# Date created:		Mar 5, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rotfl
PORTVERSION=	0.6.4
CATEGORIES=	lang
MASTER_SITES=	http://www.bangmoney.org/projects/rotfl/ \
		ftp://ftp.bangmoney.org/pub/rotfl/

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	rotfl.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rotfl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/rotfl
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/rotfl/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/rotfl/docs
.for file in HOWTO README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/rotfl/docs
.endfor
.endif

.include <bsd.port.mk>
