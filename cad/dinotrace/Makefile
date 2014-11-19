# Created by: Joachim Strombergson <watchman@ludd.ltu.se>
# $FreeBSD$

PORTNAME=	dinotrace
PORTVERSION=	9.4c
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.org/ftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical signal trace waveform viewer

OPTIONS_DEFINE=	EMACS
OPTIONS_DEFAULT=	EMACS
EMACS_DESC=	Install Emacs supplimentary files

USE_XORG=	x11 sm ice xmu xt
USES=		gmake motif perl5 tar:tgz
USE_PERL5=	build
GNU_CONFIGURE=	yes

INFO=		dinotrace
PLIST_FILES=	bin/dinotrace

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMACS}
RUN_DEPENDS+=	verilog-mode.el>0:${PORTSDIR}/cad/verilog-mode.el
USE_EMACS=	yes
EMACS_NO_BUILD_DEPENDS=	yes
.for F in dinotrace.el sim-log.el
PLIST_FILES+=	${EMACS_SITE_LISPDIR}/${F}
.endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"-O3"|""|' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MEMACS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.for F in dinotrace.el sim-log.el
	${INSTALL_DATA} ${WRKSRC}/lisp/${F} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.endfor
.endif

.include <bsd.port.mk>
