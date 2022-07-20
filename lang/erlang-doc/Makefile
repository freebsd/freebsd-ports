PORTNAME=	erlang
PORTVERSION=	24.3
CATEGORIES=	lang parallel
MASTER_SITES=	http://www.erlang.org/download/:erlangorg \
		http://erlang.stacken.kth.se/download/:erlangorg \
		http://www.csd.uu.se/ftp/mirror/erlang/download/:erlangorg \
		http://olgeni.olgeni.com/~olgeni/distfiles/:local \
		LOCAL/olgeni:local \
		http://www.erlang.se/doc/:erlangse \
		http://www.erlang.se/publications/:publications \
		http://www.sics.se/~joe/thesis/:joe
PKGNAMESUFFIX=	-doc
DISTNAME=	otp_doc_html_${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:erlangorg \
		${BOOK_DISTFILES}
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang documentation

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-message

BOOK_DISTFILES=	armstrong_thesis_2003.pdf:local \
		bjarnelic.pdf:publications \
		erlang-book-part1.pdf:erlangorg \
		master_thesis_patterns.pdf:local \
		mnesia_overview.pdf:publications \
		programming_rules.pdf:erlangse

do-extract:
	@${MKDIR} ${WRKSRC}
	${TAR} -xzf ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} --directory ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)
.for FILE in ${BOOK_DISTFILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$(expr ${FILE} : '\([^:]*\)') ${STAGEDIR}/${DOCSDIR}/pdf
.endfor

.include <bsd.port.mk>
