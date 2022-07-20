PORTNAME=	lmpc
PORTVERSION=	3.4.4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://demospecs.half-empty.de/lmpc-alpha/:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FETCHED_DOCS:S/$/:doc/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tools to manipulate some FPS games demo recordings

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	armv6 armv7 i386 mips powerpc
ONLY_FOR_ARCHS_REASON=	assumes sizeof(long) == 4

USES=		gmake perl5 shebangfix
GNU_CONFIGURE=	yes
USE_PERL5=	build
SHEBANG_FILES=	bin/procdm2.pl

PORTSCOUT=	limit:.*[0-9]$$		# letter-suffixed files are binaries

SCRIPTS=	dema dm2cat procdm2.pl
PROGRAMS=	dbs demcut lmpc
FETCHED_DOCS=	${PORTNAME}.html ${PORTNAME}.pdf ${PORTNAME}.sgml
PORTDOCS=	*
PLIST_FILES=	${SCRIPTS:S,^,bin/,} ${PROGRAMS:S,^,bin/,}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,bin doc src spec,bin src,' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,^record\.o,dbs.o demcut.o demotexty.o \
		lmpc.o record.o udem.o udeml.o udm2.o udm3.o uqwd.o,' \
			${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/bin/,} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/src/,} \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FETCHED_DOCS:S,^,${DISTDIR}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
