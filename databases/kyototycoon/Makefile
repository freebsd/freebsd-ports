# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyototycoon
PORTVERSION=	0.9.56
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handy cache/storage server

LICENSE=	GPLv3

LIB_DEPENDS=	libkyotocabinet.so:${PORTSDIR}/databases/kyotocabinet

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--enable-uyield
CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
MAKE_ARGS=	PCDIR=${PREFIX}/libdata/pkgconfig
REINPLACE_ARGS=	-i ''
USE_LDCONFIG=	yes
USES=		gmake pkgconfig

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|g; s|-lstdc++ ||g' ${WRKSRC}/configure ${WRKSRC}/doc/spex.html ${WRKSRC}/example/Makefile
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/DOCDIR/d' ${WRKSRC}/Makefile.in
.endif

post-build:
	@cd ${WRKSRC}/ && ${STRIP_CMD} ktplugdbvoid.so ktplugservmemc.so \
		ktremotemgr ktremotetest ktserver kttimedmgr kttimedtest \
		ktutilmgr ktutilserv ktutiltest

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type d -exec ${CHMOD} 755 '{}' \;
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type f -exec ${CHMOD} 444 '{}' \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}/
.endif

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
