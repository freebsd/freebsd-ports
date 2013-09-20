# Created by: rv@FreeBSD.org
# $FreeBSD$

PORTNAME=	cons-test
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.dsmit.com/cons/stable/ \
		http://www.gnu.org/software/cons/stable/ \
		ftp://ftp.gnu.org/pub/old-gnu/cons/ \
		http://www.baldmt.com/cons/stable/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A test bed for `Cons' development

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/cons:${PORTSDIR}/devel/cons

WRKSRC=		${WRKDIR}/cons-${PORTVERSION}/test
NO_BUILD=	yes

USES=		perl5
PLIST_SUB=	CONS_VER="${PORTVERSION}" CONS_TEST="${CONS_TEST}"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-test//}-${PORTVERSION}/test

MANCOMPRESSED=	yes
MAN1=		cons-test.1

CONS_TEST=	cons-${PORTVERSION}/test
DOCS=		CHANGES COPYRIGHT README TODO Tests.txt
TESTS=		1..83,101..147
TEST_LIBS=	Cmd.pm Cons.pm

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's:/usr/lib:${PREFIX}/lib:g' \
		${WRKSRC}/cons-test

do-install:
#
# Install the script
#
	${INSTALL_SCRIPT} ${WRKSRC}/cons-test \
		${PREFIX}/bin
#
# Install the tests
#
	${MKDIR} ${PREFIX}/lib/${CONS_TEST}/t
	${PERL} -e 'for (${TESTS}) {$$f=sprintf "t%04d.t", $$_;\
		    $$x= "${INSTALL_DATA} ${WRKSRC}/t/$$f \
			    ${PREFIX}/lib/${CONS_TEST}/t";\
		    printf "$$x\n"; system $$x;}'
#
# Install the test libraries
#
	${MKDIR} ${PREFIX}/lib/${CONS_TEST}/Test/Cmd
	${INSTALL_DATA} ${WRKSRC}/Test/Cmd.pm ${PREFIX}/lib/${CONS_TEST}/Test
	${INSTALL_DATA} ${WRKSRC}/Test/Cmd/Cons.pm \
	    ${PREFIX}/lib/${CONS_TEST}/Test/Cmd
#
# Install the man pages
#
	${INSTALL_MAN} ${WRKSRC}/cons-test.1.gz \
		${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
#
# Install the documentation
#
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
