# Date created:         2010-11-23
# Whom:                 Wen Heping <wenheping@gmail.com>
#

.if ${ARCH} == "i386"
GOARCH=	386
GOOBJ=	8
GOOS=	freebsd
.else
GOARCH=	amd64
GOOBJ=	6
GOOS=	freebsd
.endif

GO_CMD=		${LOCALBASE}/bin/${GOOBJ}g
GOROOT_REL=	lib/go
GOROOT=		${LOCALBASE}/${GOROOT_REL}
GO_LIBDIR=	${GOROOT_REL}/pkg/${GOOS}_${GOARCH}

.if defined(USE_GO)
BUILD_DEPENDS+=	${GO_CMD}:${PORTSDIR}/lang/go
RUN_DEPENDS+=	${GO_CMD}:${PORTSDIR}/lang/go

USE_GMAKE=	yes

MAKE_ENV+=	GOROOT=${GOROOT} GOARCH=${GOARCH} GOOS=${GOOS}

PLIST_SUB+=	GO_LIBDIR=${GO_LIBDIR}
.endif


.if defined(USE_GO)
do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} install)
.endif
