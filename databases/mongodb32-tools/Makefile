# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	mongodb32-tools
PORTVERSION=	3.2.11
DISTVERSIONPREFIX=	r
CATEGORIES=	databases net

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	Tools for MongoDB

LICENSE=	APACHE20

BUILD_DEPENDS=	go>0:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo-tools

OPTIONS_DEFINE=	SSL SASL
OPTIONS_DEFAULT=	SSL

SASL_USE=	my_tags=sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

SSL_USE=	openssl=yes my_tags=ssl

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than i386 and amd64"

STRIP=		# Stripping can break go binaries

# Go is not our friend. Without below, ignores user-supplied flags.
MAKE_CMD=	${LOCALBASE}/bin/go build
MAKE_ENV=	GOPATH="${WRKSRC}/.gopath:${WRKSRC}/vendor" \
		CGO_CFLAGS="${CFLAGS}" CGO_CPPFLAGS="${CPPFLAGS}" \
		CGO_CXXFLAGS="${CXXFLAGS}" CGO_LDFLAGS="${LDFLAGS}"

USES=	localbase
MY_TAGS=	-tags "${USE_MY_TAGS}"

post-patch:
	@cd ${WRKSRC} ; ${MKDIR} ${WRKSRC}/.gopath/src/github.com/${GH_ACCOUNT} ; \
		${LN} -sf ${WRKSRC} ${WRKSRC}/.gopath/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

do-build:
.for x in bsondump mongostat mongofiles mongoexport mongoimport mongorestore mongodump mongotop mongooplog
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		-o ${WRKSRC}/bin/${x} ${MY_TAGS}\
		-ldflags "-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/common/options.Gitspec=${GH_TAGNAME}"\
		${WRKSRC}/${x}/main/${x}.go
.endfor

do-install:
.for x in bsondump mongostat mongofiles mongoexport mongoimport mongorestore mongodump mongotop mongooplog
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${x} ${STAGEDIR}${PREFIX}/bin/
.endfor

	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in LICENSE.md README.md THIRD-PARTY-NOTICES
	${INSTALL_MAN} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
