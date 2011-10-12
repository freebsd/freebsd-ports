# New ports collection makefile for:	Litte Movie Processing Centre
# Date created:				16 Mar 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lmpc
PORTVERSION=	3.4.4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://demospecs.half-empty.de/lmpc-alpha/:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FETCHED_DOCS:S/$/:doc/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A tool to manipulate games demo recordings

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

PORTSCOUT=	limit:.*[0-9]$$		# letter-suffixed files are binaries

SCRIPTS=	dema dm2cat procdm2.pl
PROGRAMS=	dbs demcut lmpc
FETCHED_DOCS=	${PORTNAME}.html ${PORTNAME}.pdf ${PORTNAME}.sgml
PORTDOCS=	*
PLIST_FILES=	${SCRIPTS:S,^,bin/,} ${PROGRAMS:S,^,bin/,}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		does not work on ${ARCH}: assumes sizeof(long) == 4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,bin doc src spec,bin src,' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/bin/,} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/src/,} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${FETCHED_DOCS:S,^,${DISTDIR}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
