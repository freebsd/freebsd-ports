# Ports collection makefile for:  go
# Date created:			  04 December 2010
# Whom:				  Devon H. O'Dell <devon.odell@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	go
PORTVERSION=	20101225
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	LOCAL/wen
DISTNAME=	go-${PORTVERSION}

MAINTAINER=	devon.odell@gmail.com
COMMENT=	An experimental, concurrent, garbage-collected language

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		bison:${PORTSDIR}/devel/bison

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
GOMAKEDIR=	lib/go/src
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

GOBIN=		${WRKDIR}/bin
MAKE_ENV=	GOROOT=${WRKSRC}	\
		GOARCH=${GOARCH}	\
		GOBIN=${GOBIN}		\
		GOOS=freebsd
PLIST_SUB+=	ARCH=${GOARCH}		\
		GOOBJ=${GOOBJ} \
		GOMAKEDIR=${GOMAKEDIR}

pre-build:
	@${MKDIR} ${GOBIN}

.if !defined(MAINTAINER_MODE)
do-build:
	(cd ${WRKSRC}/src &&		\
		GOROOT=${WRKSRC}	\
		GOARCH=${GOARCH}	\
		GOBIN=${GOBIN}		\
		GOOS=freebsd		\
		bash make.bash)
.else
	(cd ${WRKSRC}/src &&		\
		GOROOT=${WRKSRC}	\
		GOARCH=${GOARCH}	\
		GOBIN=${GOBIN}		\
		GOOS=freebsd		\
		bash all.bash)
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

do-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif
	${INSTALL} -d -m 0755 ${PREFIX}/${GOMAKEDIR}
	${INSTALL} -d -m 0755 ${PREFIX}/lib/go/pkg
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.common ${PREFIX}/${GOMAKEDIR}
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.pkg ${PREFIX}/${GOMAKEDIR}
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.cmd ${PREFIX}/${GOMAKEDIR}
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.ccmd ${PREFIX}/${GOMAKEDIR}
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.clib ${PREFIX}/${GOMAKEDIR}
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.inc ${PREFIX}/${GOMAKEDIR}
	${CP} -R ${WRKSRC}/pkg/* ${PREFIX}/lib/go/pkg/
	${CP} -R ${WRKDIR}/bin/* ${PREFIX}/bin/

.include <bsd.port.post.mk>
