PORTNAME=	jpm
DISTVERSION=	0.0.2
CATEGORIES=	lang

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Janet Project Manager tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	janet>=1.17.2:lang/janet

USE_GITHUB=	yes
GH_ACCOUNT=	janet-lang
NO_BUILD=	yes

# JANET_* might interfere with the install
MAKE_ENV=	-uJANET_MODPATH \
		-uJANET_PATH \
		DESTDIR=${STAGEDIR}

.include <bsd.port.pre.mk>

.if ${PREFIX} != /usr/local
post-patch:
	@${REINPLACE_CMD} s,"/usr/local","${PREFIX}", \
		${WRKSRC}/configs/bsd_config.janet
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/janet
	@cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} janet bootstrap.janet configs/bsd_config.janet || ${TRUE}
.if ${PREFIX} != /usr/local
# XXX: Something always creates /usr/local/lib/janet ?
	@${RMDIR} ${STAGEDIR}/usr/local/lib/janet
.endif

.include <bsd.port.post.mk>
