# $FreeBSD$

PORTNAME=	usql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal command-line interface for SQL databases

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	xo

GH_TUPLE=	xo:dburl:2406b5c:dburl/src/github.com/xo/dburl \
		xo:terminfo:b44407a:terminfo/src/github.com/xo/terminfo \
		xo:xoutil:46189f4:xoutil/src/github.com/xo/xoutil \
		alecthomas:chroma:v0.3.0:chroma/src/github.com/alecthomas/chroma \
		alexflint:go-arg:0cc8e30:goarg/src/github.com/alexflint/go-arg \
		danwakefield:fnmatch:cbb64ac:fnmatch/src/github.com/danwakefield/fnmatch \
		denisenkom:go-mssqldb:ee49270:gomssqldb/src/github.com/denisenkom/go-mssqldb \
		dlclark:regexp2:v1.1.6:regexp2/src/github.com/dlclark/regexp2 \
		go-sql-driver:mysql:v1.3:mysql/src/github.com/go-sql-driver/mysql \
		gohxs:readline:a780388:readline/src/github.com/gohxs/readline \
		lib:pq:88edab0:pq/src/github.com/lib/pq \
		mattn:go-isatty:v0.0.3:goisatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:gorunewidth/src/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.6.0:gosqlite3/src/github.com/mattn/go-sqlite3 \
		olekukonko:tablewriter:b8a9be0:tablewriter/src/github.com/olekukonko/tablewriter \
		zaf:temp:94e3859:temp/src/github.com/zaf/temp \
		golang:crypto:650f4a3:crypto/src/golang.org/x/crypto
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

PLIST_FILES=	bin/usql

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/usql ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
