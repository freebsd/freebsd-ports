# $FreeBSD$

PORTNAME=	mongodb40-tools
DISTVERSIONPREFIX=	r
DISTVERSION=	4.0.8
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	dev.ashevchuk@gmail.com
COMMENT=	Tools for MongoDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to other architectures

USES=		compiler:c++14-lang go localbase
USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo-tools

GO_BUILDFLAGS=	-tags "${USE_MY_TAGS}"
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	${TOOL_BUILD:C,(.*),github.com/${GH_ACCOUNT}/${GH_PROJECT}/\1/\1,}

CONFLICTS_INSTALL=	mongodb3[46] mongodb3[46]-tools

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	MONGODUMP MONGOEXPORT MONGOFILES MONGOIMPORT \
			MONGORESTORE SASL SSL
OPTIONS_MULTI=		SECURITY TOOLS
OPTIONS_MULTI_TOOLS=	BSONDUMP MONGODUMP MONGOEXPORT MONGOFILES MONGOIMPORT \
			MONGOREPLAY MONGORESTORE MONGOSTAT MONGOTOP
OPTIONS_MULTI_SECURITY=	SASL SSL
OPTIONS_SUB=		yes

BSONDUMP_DESC=		BSON files into human-readable formats
MONGOSTAT_DESC=		Status of a running mongod or mongos instance
MONGOFILES_DESC=	Interface to GridFS in a MongoDB instance
MONGOEXPORT_DESC=	JSON or CSV export of MongoDB instance data
MONGOIMPORT_DESC=	Importing JSON, CSV, or TSV into a MongoDB instance
MONGORESTORE_DESC=	BSON data to a MongoDB instance
MONGODUMP_DESC=		BSON data from the contents of a MongoDB instance
MONGOTOP_DESC=		Track the amount of data I/O time
MONGOREPLAY_DESC=	Traffic capture and replay tool

BSONDUMP_VARS=		tool_build+=bsondump
MONGOSTAT_VARS=		tool_build+=mongostat
MONGOFILES_VARS=	tool_build+=mongofiles
MONGOEXPORT_VARS=	tool_build+=mongoexport
MONGOIMPORT_VARS=	tool_build+=mongoimport
MONGORESTORE_VARS=	tool_build+=mongorestore
MONGODUMP_VARS=		tool_build+=mongodump
MONGOTOP_VARS=		tool_build+=mongotop
MONGOREPLAY_VARS=	tool_build+=mongoreplay
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_USE=		my_tags=sasl
SSL_USES=		ssl
SSL_USE=		my_tags=ssl

.include <bsd.port.options.mk>

# Rename 'main' directories to the tool names so that the binaries
# are not all named 'main' and we do not have to hack around USES=go.
post-patch:
.for tool in ${TOOL_BUILD}
	@${MV} ${WRKSRC}/${tool}/main ${WRKSRC}/${tool}/${tool}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in README.md CONTRIBUTING.md THIRD-PARTY-NOTICES
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
