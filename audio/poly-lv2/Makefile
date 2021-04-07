PORTNAME=	poly
DISTVERSION=	g20201118
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LV2 plugins designed for modular/eurorack style use

#LICENSE=	not defined in the repository: https://github.com/polyeffects/PolyLV2/issues/2

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/boost/circular_buffer.hpp:devel/boost-libs

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	polyeffects
GH_PROJECT=	PolyLV2
GH_TAGNAME=	3fd1dd4

do-build:
	@cd ${WRKSRC} && for d in $$(ls); do \
		if [ -d $${d} ]; then \
			echo "==> Building for sub-directory $${d}" && ( \
				cd $${d} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} \
			) \
		fi \
	done

do-install:
	@cd ${WRKSRC} && for d in $$(ls); do \
		if [ -d $${d} ]; then \
			echo "==> Staging for sub-directory $${d}" && ( \
				cd $${d} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${INSTALL_TARGET} \
			) \
		fi \
	done

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/basic_modular.lv2/maths.so

.include <bsd.port.mk>
