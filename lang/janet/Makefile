PORTNAME=	janet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.42.0
CATEGORIES=	lang

MAINTAINER=	bsd.hsw@gmail.com
COMMENT=	Functional embeddable lisp with C interop, & performant data types
WWW=		https://janet-lang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		inotify meson
USE_GITHUB=	yes
GH_ACCOUNT=	janet-lang
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION} \
		SOVERSION_R=${DISTVERSION:R}

# if it has native (not port) use that for filewatch otherwise let it use kqueue.
# Once FreeBSD14.4 is retired merge upstream.
.include <bsd.port.pre.mk>
post-patch:
.if defined(INOTIFY_PORT)
	${REINPLACE_CMD} -e 's:%INOTIFY%::' ${WRKSRC}/src/core/filewatch.c
	${REINPLACE_CMD} -e 's|%KQUEUE%|:freebsd|' -e 's|%INOTIFY%||' \
		${WRKSRC}/test/suite-filewatch.janet
.else
	${REINPLACE_CMD} -e 's:%INOTIFY%:|| defined(__FreeBSD__):' ${WRKSRC}/src/core/filewatch.c
	${REINPLACE_CMD} -e 's|%KQUEUE%||' -e 's|%INOTIFY%|:freebsd|' \
		${WRKSRC}/test/suite-filewatch.janet
.endif
.include <bsd.port.post.mk>
