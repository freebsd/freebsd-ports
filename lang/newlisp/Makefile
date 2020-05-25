# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	newlisp
PORTVERSION=	10.7.5
CATEGORIES=	lang
MASTER_SITES=	http://www.newlisp.org/downloads/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	LISP like scripting language

LICENSE=	GPLv3

LIB_DEPENDS=	libffi.so:devel/libffi

CONFLICTS=	newlisp-devel-[0-9]*

USES=		readline:port tar:tgz
OPTIONS_SUB=	yes

HAS_CONFIGURE=	yes
ALL_TARGET=	default

REINPLACE_ARGS=	-i ""

MODULES=	canvas cgi crypto ftp getopts infix odbc plot pop3 \
		postscript smtp smtpx stat unix xmlrpc-client zlib

DOCS=		ANDROID.txt Android.html CHANGES COPYING CREDITS \
		CodePatterns.html ExpressionEvaluation.html INSTALL \
		LOCALIZATION License.html MemoryManagement.html \
		manual_frame.html newLISP-${PORTVERSION}-Release.html \
		newLISPdoc.html newlisp-man.txt newlisp_index.html \
		newlisp_manual.html newlispdoc-man.txt

OPTIONS_DEFINE=	DOCS EXAMPLES GSL MYSQL PGSQL SQLITE
GSL_DESC=	GSL (GNU Scientific Library)

.include <bsd.port.options.mk>

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
CFLAGS+=	-DNEWLISP64
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	libgsl.so:math/gsl
MODULES+=	gsl
.endif

.if ${PORT_OPTIONS:MMYSQL}
USES+=		mysql
MODULES+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
MODULES+=	postgres
.endif

.if ${PORT_OPTIONS:MSQLITE}
USES+=		sqlite
MODULES+=	sqlite3
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
