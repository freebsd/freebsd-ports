# Created by: Joachim Strombergson <watchman@ludd.ltu.se>
# $FreeBSD$

PORTNAME=	dinotrace
PORTVERSION=	9.4c
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.org/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical signal trace waveform viewer

OPTIONS_DEFINE=	EMACS
OPTIONS_DEFAULT=	EMACS
EMACS_DESC=	Install Emacs supplimentary files

USE_XORG=	x11 sm ice xmu xt
USES=		gmake motif
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

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
	@${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}
.for F in dinotrace.el sim-log.el
	${INSTALL_DATA} ${WRKSRC}/lisp/${F} ${PREFIX}/${EMACS_SITE_LISPDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
