PORTNAME=	raul
DISTVERSION=	2.0.0
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Realtime modular synthesizer and/or effects processor
WWW=		https://drobilla.net/software/raul.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c++11-lang meson tar:xz

MESON_ARGS=	-Dtests=disabled # tests pass when this line is removed and do-test is removed

NO_ARCH=	yes

do-test: # Tests fail to configure, see https://github.com/drobilla/raul/issues/2
	@cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} --reconfigure ${CONFIGURE_ARGS} -Dtests=enabled && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} test

.include <bsd.port.mk>
