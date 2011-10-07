# Ports collection makefile for:  go
# Date created:			  04 December 2010
# Whom:				  Devon H. O'Dell <devon.odell@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	go
PORTVERSION=	20111005
CATEGORIES=	lang
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	An experimental, concurrent, garbage-collected language

LICENSE=	BSD

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		bison:${PORTSDIR}/devel/bison

ONLY_FOR_ARCHS=	i386 amd64
USE_XZ=		yes
USE_GMAKE=	yes
SUB_FILES=	pkg-message
SUB_LIST+=	GOOBJ=${GOOBJ} \
		ARCH=${GOARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
GOARCH=386
GOOBJ=8
.else
GOARCH=amd64
GOOBJ=6
.endif

PLIST_SUB+=	ARCH=${GOARCH}		\
		GOOBJ=${GOOBJ}

do-build:
	(cd ${WRKSRC}/src &&		\
		GOROOT=${WRKSRC}	\
		GOARCH=${GOARCH}	\
		GOOS=freebsd		\
		bash make.bash)

post-install:
	@${CAT} ${PKGMESSAGE}

do-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif
	${CP} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${INSTALL} -d -m 0755 ${PREFIX}/go/pkg
	${CP} -R ${WRKSRC}/pkg/* ${PREFIX}/go/pkg/
	${INSTALL} -d -m 0755 ${PREFIX}/go/src/
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.* ${PREFIX}/go/src/

.include <bsd.port.post.mk>
