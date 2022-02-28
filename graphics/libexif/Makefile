# Created by: Peter Schmiedeskamp <pschmied@qwest.net>

PORTNAME=	libexif
PORTVERSION=	0.6.24
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/libexif/libexif/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to read digital camera file meta-data

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake libtool localbase pathfix pkgconfig tar:bzip2

CONFIGURE_ARGS=	--disable-docs
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

CPE_VENDOR=	libexif_project

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENV_OFF=	am_cv_func_iconv=no
NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
