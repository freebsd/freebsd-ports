# New ports collection makefile for:	devel/p5-Rcs
# Date created:				21 November 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Rcs
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Rcs
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Rcs.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLES=	access.pl ci-tree.pl ci.pl co-tree.pl co.pl \
		comments.pl comments2.pl daterev.pl dates.pl \
		green.txt mark.pl parse.pl pause \
		project/RCS/Rcs.pm,v project/RCS/testfile,v \
		project/src/Rcs.pm project/src/testfile \
		rcsclean.pl rcsdiff.pl revdate.pl rlog.pl \
		symbols.pl symrev.pl test1.pl test2.pl test3.pl \
		type unlock.pl

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/project
	${MKDIR} ${EXAMPLESDIR}/project/RCS
	${MKDIR} ${EXAMPLESDIR}/project/src
.for _EXAMPLE in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${_EXAMPLE} ${EXAMPLESDIR}/${_EXAMPLE}
.endfor

.include <bsd.port.mk>
