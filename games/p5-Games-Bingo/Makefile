# New ports collection makefile for:	p5-Games-Bingo
# Date created:				14. August 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Games-Bingo
PORTVERSION=	0.13
CATEGORIES=	games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Games
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A bingo game Perl implementation

PERL_MODBUILD=	yes

MAN3=		Games::Bingo.3 \
		Games::Bingo::Card.3 \
		Games::Bingo::Column.3 \
		Games::Bingo::ColumnCollection.3 \
		Games::Bingo::Constants.3

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e '$$_="" if /Test::/' ${WRKSRC}/Build.PL

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing example for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bingo.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
