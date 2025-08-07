PORTNAME=	mongodb-tools
DISTVERSION=	100.12.2
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	MongoDB Database Tools
WWW=		https://www.mongodb.com/docs/database-tools/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		compiler:c++14-lang go:1.23 localbase
USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo-tools

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_BUILDFLAGS=	-tags "${USE_MY_TAGS}"

# This should be TEST_ENV according to bsd.port.mk, but Uses/go.mk passes
# MAKE_ENV instead of TEST_ENV in the do-test target.
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=284387
MAKE_ENV+=		TOOLS_TESTING_UNIT=true

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	BSONDUMP MONGODUMP MONGOEXPORT MONGOFILES MONGOIMPORT \
			MONGORESTORE MONGOSTAT MONGOTOP \
			SASL SSL
OPTIONS_MULTI=		SECURITY TOOLS
OPTIONS_MULTI_SECURITY=	SASL SSL
OPTIONS_MULTI_TOOLS=	BSONDUMP MONGODUMP MONGOEXPORT MONGOFILES MONGOIMPORT \
			MONGORESTORE MONGOSTAT MONGOTOP
OPTIONS_SUB=		yes

BSONDUMP_DESC=		BSON files into human-readable formats
MONGODUMP_DESC=		BSON data from the contents of a MongoDB instance
MONGOEXPORT_DESC=	JSON or CSV export of MongoDB instance data
MONGOFILES_DESC=	Interface to GridFS in a MongoDB instance
MONGOIMPORT_DESC=	Importing JSON, CSV, or TSV into a MongoDB instance
MONGORESTORE_DESC=	BSON data to a MongoDB instance
MONGOSTAT_DESC=		Status of a running mongod or mongos instance
MONGOTOP_DESC=		Track the amount of data I/O time

BSONDUMP_VARS=		go_target+=./bsondump/main:bsondump
MONGODUMP_VARS=		go_target+=./mongodump/main:mongodump
MONGOEXPORT_VARS=	go_target+=./mongoexport/main:mongoexport
MONGOFILES_VARS=	go_target+=./mongofiles/main:mongofiles
MONGOIMPORT_VARS=	go_target+=./mongoimport/main:mongoimport
MONGORESTORE_VARS=	go_target+=./mongorestore/main:mongorestore
MONGOSTAT_VARS=		go_target+=./mongostat/main:mongostat
MONGOTOP_VARS=		go_target+=./mongotop/main:mongotop
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_USE=		my_tags=sasl
SSL_USE=		my_tags=ssl

post-extract:
# Verify we use the proper go version.
	${SH} -xc "test \"X`grep -E '^go [[:digit:]]+\.[[:digit:]]+\.[[:digit:]]+$$' ${WRKSRC}/go.mod`\" = \"Xgo ${GO_VERSION}.0\""

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in README.md CONTRIBUTING.md THIRD-PARTY-NOTICES
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
