# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyototycoon
PORTVERSION=	0.9.56
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handy cache/storage server

LICENSE=	GPLv3

LIB_DEPENDS=	kyotocabinet:${PORTSDIR}/databases/kyotocabinet

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--enable-profile --enable-uyield
GNU_CONFIGURE=	yes
MAKE_ARGS=	PCDIR="${PREFIX}/libdata/pkgconfig"
USE_LDCONFIG=	yes
USES=		gmake

MAN1=		ktremotemgr.1 \
		ktremotetest.1 \
		ktserver.1 \
		kttimedmgr.1 \
		kttimedtest.1 \
		ktutilmgr.1 \
		ktutilserv.1 \
		ktutiltest.1

.include <bsd.port.options.mk>

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/DOCDIR/d' ${WRKSRC}/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${FIND} ${DOCSDIR}/ -type d -exec ${CHMOD} 755 '{}' \;
	${FIND} ${DOCSDIR}/ -type f -exec ${CHMOD} 444 '{}' \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/
.endif

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
