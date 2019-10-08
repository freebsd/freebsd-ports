# $FreeBSD$

PORTNAME=	go14
PORTVERSION=	1.4.3
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	https://dl.google.com/go/
DISTNAME=	go1.4-bootstrap-20171003

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Go programming language

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		amd64 armv6 armv7 i386

USES=		compiler shebangfix

SHEBANG_GLOB=	*.bash *.pl *.cgi

WRKSRC=		${WRKDIR}/go

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
GOARCH=386
GOOBJ=8
.elif ${ARCH} == amd64
GOARCH=amd64
GOOBJ=6
.elif ${ARCH} == armv6 || ${ARCH} == armv7
GOARCH=arm
GOOBJ=5
.else
IGNORE=		unknown arch ${ARCH}
.endif

PLIST_SUB+=	ARCH=${GOARCH} \
		GOOBJ=${GOOBJ}

post-patch:
	@cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete
	@${REINPLACE_CMD} -e 's|^if ulimit -T|false \&\& &|' ${WRKSRC}/src/run.bash
	@${REINPLACE_CMD} -e 's|<<<.int main() {}.|< $$\(echo "int main() {}"\)|' ${WRKSRC}/src/run.bash

do-build:
	cd ${WRKSRC}/src && \
		GOROOT=${WRKSRC} GOROOT_FINAL=${PREFIX}/go14 \
		GOBIN= GOARCH=${GOARCH} GOOS=${OPSYS:tl} \
		GO386=387 \
		CGO_ENABLED=0 \
		${SH} make.bash

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/go14
	( cd ${WRKSRC} ; \
		${COPYTREE_BIN} "bin pkg/tool" ${STAGEDIR}${PREFIX}/go14 ; \
		${RM} -r pkg/${OPSYS:tl}_${GOARCH}/cmd ; \
		${COPYTREE_SHARE} " \
			[A-Z]* \
			include \
			pkg/${OPSYS:tl}_${GOARCH} \
			src" \
		${STAGEDIR}${PREFIX}/go14 )

do-test:
	cd ${WRKSRC}/src && GOROOT=${WRKSRC} PATH=${WRKSRC}/bin:${PATH} ${SH} run.bash --no-rebuild --banner

.include <bsd.port.post.mk>
