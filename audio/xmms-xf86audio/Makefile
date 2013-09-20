# $FreeBSD$

PORTNAME=	xmms-xf86audio
PORTVERSION=	0.4.4
CATEGORIES=	audio
MASTER_SITES=	http://www.devin.com/xmms-xf86audio/download/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XF86Audio multimedia-key support for XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

MAKE_ARGS=	CC="${CC}" OPT="${CFLAGS}" DEBUG=""
NO_STAGE=	yes

.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/libxf86audio.so \
		`xmms-config --general-plugin-dir`
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
