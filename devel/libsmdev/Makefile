# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsmdev
DISTVERSION=	alpha-20160109
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libsmdev/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library to access to storage media devices

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python --with-libintl-prefix=${LOCALBASE}
USES=		gettext libtool pathfix python
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

PORTDOCS=	AUTHORS ChangeLog

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# posix_fadvise(2) did not return correct value on error
.if (${OSVERSION} >= 1100000 && ${OSVERSION} < 1100007) || (${OSVERSION} >= 1000000 && ${OSVERSION} < 1000703) || (${OSVERSION} < 902507)
CONFIGURE_ENV+=	ac_cv_func_posix_fadvise=no
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
