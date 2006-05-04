# New ports collection makefile for:	libopensync
# Date created:		2005-06-19
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libopensync
PORTVERSION=	0.17
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.opensync.org/attachment/wiki/download/
MASTER_SITE_SUBDIR=	ahze
EXTRACT_SUFX=	.tar.gz\?rev=\&format=raw

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Freedesktop synchronization framework

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack glib20 libxml2
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not build on FreeBSD 4.x"
.endif

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

pre-everything::
	@${ECHO_MSG} "NOTE: You may want to avoid extra dependencies"
	@${ECHO_MSG} " from devel/swig13 by building with the following"
	@${ECHO_MSG} " SWIG_LANGUAGES=\"perl python\""
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
