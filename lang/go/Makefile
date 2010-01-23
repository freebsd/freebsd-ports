# Ports collection makefile for:  go
# Date created:			  04 December 2010
# Whom:				  Devon H. O'Dell <devon.odell@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	go
PORTVERSION=	20100113
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.atarininja.org/~wxs/distfiles/
MASTER_SITE_SUBDIR=	wxs
DISTNAME=	go-${PORTVERSION}

MAINTAINER=	devon.odell@gmail.com
COMMENT=	An experimental, concurrent, garbage-collected language

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		bison:${PORTSDIR}/devel/bison

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	${WRKSRC}/src/Makefile
.if !defined(MAINTAINER_MODE)
ALL_TARGET=	build
.endif

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
		GOOBJ=${GOOBJ}

pre-build:
	@${MKDIR} ${GOBIN}

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED}		\
		-e "s|%%PREFIX%%|${PREFIX}|g"	\
		-e "s|%%ARCH%%|${GOARCH}|g"	\
		-e "s|%%GOOBJ%%|${GOOBJ}|g"

do-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif
	${INSTALL} -d -m 0755 ${DATADIR}
	${INSTALL} -d -m 0755 ${PREFIX}/lib/go
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.${GOARCH} ${DATADIR}
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.pkg ${DATADIR}
	${INSTALL} -m 0644 ${WRKSRC}/src/Make.cmd ${DATADIR}
	${CP} -R ${WRKSRC}/pkg/ ${PREFIX}/lib/go
	${CP} -R ${WRKDIR}/bin/ ${PREFIX}/bin

.include <bsd.port.post.mk>
