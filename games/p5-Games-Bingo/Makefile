# New ports collection makefile for:	p5-Games-Bingo
# Date created:				14. August 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Games-Bingo
PORTVERSION=	0.10
CATEGORIES=	games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Games
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	A bingo game Perl implementation

PERL_CONFIGURE=	yes

MAN3=		Games::Bingo.3 \
		Games::Bingo::Card.3 \
		Games::Bingo::Column.3 \
		Games::Bingo::ColumnCollection.3 \
		Games::Bingo::Constants.3

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete

.if ${PERL_LEVEL} < 500601
# damn old MakeMaker...
post-configure:
	${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing example for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bingo.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
