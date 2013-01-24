# Created by: Devon H. O'Dell <devon.odell@gmail.com>
# $FreeBSD$

PORTNAME=	go
PORTVERSION=	1.0.3
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	go${PORTVERSION}.src

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	A concurrent, garbage-collected language

LICENSE=	BSD

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		bison:${PORTSDIR}/devel/bison

WRKSRC=		${WRKDIR}/go
ONLY_FOR_ARCHS=	i386 amd64
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
	(cd ${WRKSRC}/src &&			\
		GOTRACEBACK=2			\
		GOROOT=${WRKSRC}		\
		GOROOT_FINAL=${PREFIX}/go	\
		GOBIN=				\
		GOARCH=${GOARCH}		\
		GOOS=freebsd			\
		bash make.bash)

post-install:
	@${CAT} ${PKGMESSAGE}

do-install:
	@${CP} -a ${WRKSRC} ${PREFIX}
.for f in go godoc gofmt
	@${LN} -s ${PREFIX}/go/bin/${f} ${PREFIX}/bin/${f}
.endfor

.include <bsd.port.post.mk>
