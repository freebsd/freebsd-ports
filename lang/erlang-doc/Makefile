PORTNAME=	erlang
DISTVERSION=	26.2
CATEGORIES=	lang parallel
MASTER_SITES=	https://github.com/erlang/otp/releases/download/OTP-${PORTVERSION}/:erlangorg \
		LOCAL/olgeni:local
PKGNAMESUFFIX=	-doc
DISTNAME=	otp_doc_html_${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:erlangorg \
		${BOOK_DISTFILES}
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang documentation
WWW=		https://www.erlang.org/

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-message

BOOK_DISTFILES=	armstrong_thesis_2003.pdf:local \
		bjarnelic.pdf:local \
		erlang-book-part1.pdf:local \
		master_thesis_patterns.pdf:local \
		mnesia_overview.pdf:local \
		programming_rules.pdf:local

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
