# New ports collection makefile for:	doxygenfilter
# Date created:		Tue Oct 28 07:38:51 UTC 2008
# Whom:			Sergei Golyashov <svvord@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	doxygenfilter
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	SF/bigsister/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	svvord@mail.ru
COMMENT=	Input filter for Doxygen enabling support for Perl code documentation

RUN_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen

USES=		perl5
USE_PERL5=	configure

MAN3=		DoxyGen::Filter.3

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${CP} ${WRKSRC}/examples/* ${PREFIX}/share/examples/${PORTNAME}/
	@cd ${WRKSRC} ; ${FIND} -s examples \! -type d | ${SED} -E 's;^examples;share/examples/${PORTNAME};' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/examples/${PORTNAME}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
