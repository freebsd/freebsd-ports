PORTNAME=	dotconf
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple, powerful configuration-file parser
WWW=		https://github.com/williamh/dotconf

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	williamh

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e "/^SUBDIRS *=/ s,doc,," \
		${WRKSRC}/Makefile.am

post-patch-EXAMPLES-on:
	@${REINPLACE_CMD} -e "/^examplesdir *=/ s, *= *.*, = ${EXAMPLESDIR}," \
		${WRKSRC}/examples/Makefile.am

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e "/^SUBDIRS *=/ s,examples,," \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
