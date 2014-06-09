# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	qico
PORTVERSION=	0.49.10.3
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.49.10-p3
DISTNAME=	${PORTNAME}-0.49.10-p3

MAINTAINER=	dsh@vlink.ru
COMMENT=	FidoNet Technology Network (FTN) compatible mailer for Unix systems

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

.if defined(WITH_QICO_AMIGA4D)
CONFIGURE_ARGS+=	--enable-aso
.endif

.if defined(WITH_QICO_MORDA)
PLIST_SUB+=	WITH_QICO_MORDA=""
.else
CONFIGURE_ARGS+=	--disable-qcc
PLIST_SUB+=	WITH_QICO_MORDA="@comment "
.endif

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/qico.conf.sample ${STAGEDIR}${PREFIX}/etc/
	${INSTALL_PROGRAM} ${WRKSRC}/src/qico ${STAGEDIR}${PREFIX}/libexec/
.if defined(WITH_QICO_MORDA)
	${INSTALL_PROGRAM} ${WRKSRC}/src/qcc ${STAGEDIR}${PREFIX}/bin/
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/qico
	${INSTALL_DATA} ${WRKSRC}/FAQ ${STAGEDIR}${PREFIX}/share/doc/qico/FAQ.ru
	${INSTALL_DATA} ${WRKSRC}/README \
		${STAGEDIR}${PREFIX}/share/doc/qico/README.ru

.include <bsd.port.mk>
