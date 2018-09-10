# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rcs
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Object Class for Revision Control System (RCS)

USES=		perl5
USE_PERL5=	configure

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLES=	access.pl ci.pl co-tree.pl co.pl comments.pl \
		comments2.pl daterev.pl dates.pl parse.pl \
		project/RCS/Rcs.pm,v project/RCS/testfile,v \
		project/src/Rcs.pm project/src/testfile rcsclean.pl \
		rcsdiff.pl revdate.pl rlog.pl symbols.pl symrev.pl \
		test1.pl test2.pl test3.pl unlock.pl

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${EXAMPLESDIR}/project/RCS \
		${STAGEDIR}${EXAMPLESDIR}/project/src
.for _EXAMPLE in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${_EXAMPLE} ${STAGEDIR}${EXAMPLESDIR}/${_EXAMPLE}
.endfor

.include <bsd.port.mk>
