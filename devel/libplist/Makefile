# $FreeBSD$

PORTNAME=	libplist
PORTVERSION=	1.12
PORTREVISION?=	0
CATEGORIES?=	devel
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Library to handle Apple Property List format

LICENSE?=	LGPL21

SLAVE_PORT?=	no

USES+=		compiler gnome libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.if ${SLAVE_PORT} == no

USE_GNOME=	libxml2
CONFIGURE_ARGS=	--without-cython
USE_LDCONFIG=	${LOCALBASE}/lib

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.endif # ${SLAVE_PORT} == no

.include <bsd.port.pre.mk>

pre-build:
.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 45
	@${REINPLACE_CMD} -e '/__attribute__/ s,deprecated(x),deprecated(),' \
		${WRKSRC}/include/plist/plist.h
.endif

.include <bsd.port.post.mk>
