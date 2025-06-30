PORTNAME=	cons-test
PORTVERSION=	2.2.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.dsmit.com/cons/stable/ \
		http://www.gnu.org/software/cons/stable/ \
		ftp://ftp.gnu.org/pub/old-gnu/cons/ \
		http://www.baldmt.com/cons/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test bed for 'Cons' development
WWW=		http://www.dsmit.com/cons/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on expired devel/cons
EXPIRATION_DATE=2025-09-30

RUN_DEPENDS=	${LOCALBASE}/bin/cons:devel/cons

USES=		perl5 tar:tgz
WRKSRC=		${WRKDIR}/cons-${PORTVERSION}/test
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB=	CONS_VER="${PORTVERSION}" CONS_TEST="${CONS_TEST}"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-test//}-${PORTVERSION}/test

CONS_TEST=	cons-${PORTVERSION}/test
PORTDOCS=	CHANGES COPYRIGHT README TODO Tests.txt
TESTS=		1..83,101..147
TEST_LIBS=	Cmd.pm Cons.pm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's:/usr/lib:${PREFIX}/lib:g' \
		${WRKSRC}/cons-test

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cons-test ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${CONS_TEST}/t
	${PERL} -e 'for (${TESTS}) {$$f=sprintf "t%04d.t", $$_;\
		    $$x= "${INSTALL_DATA} ${WRKSRC}/t/$$f \
			    ${STAGEDIR}${PREFIX}/lib/${CONS_TEST}/t";\
		    printf "$$x\n"; system $$x;}'
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${CONS_TEST}/Test/Cmd
	${INSTALL_DATA} ${WRKSRC}/Test/Cmd.pm \
		${STAGEDIR}${PREFIX}/lib/${CONS_TEST}/Test
	${INSTALL_DATA} ${WRKSRC}/Test/Cmd/Cons.pm \
		${STAGEDIR}${PREFIX}/lib/${CONS_TEST}/Test/Cmd
	${INSTALL_MAN} ${WRKSRC}/cons-test.1.gz \
		${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
