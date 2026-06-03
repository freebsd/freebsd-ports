PORTNAME=	dinotrace
PORTVERSION=	9.4f
PORTREVISION=	11
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.org/ftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical signal trace waveform viewer
WWW=		https://www.veripool.org/wiki/dinotrace

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake motif perl5 tar:tgz xorg
USE_XORG=	x11 sm ice xmu xt
USE_PERL5=	build

CONFLICTS_INSTALL=	dinotrace-emacs_*

GNU_CONFIGURE=	yes

INFO=		dinotrace
PLIST_FILES=	bin/dinotrace

OPTIONS_DEFINE=	EMACS
OPTIONS_DEFAULT=	EMACS
EMACS_DESC=	Install Emacs supplimentary files

EMACS_USES=	emacs
EMACS_RUN_DEPENDS=	verilog-mode.el>0:cad/verilog-mode.el
EMACS_PLIST_FILES=	${EMACS_SITE_LISPDIR}/dinotrace.el ${EMACS_SITE_LISPDIR}/sim-log.el

post-patch:
	@${REINPLACE_CMD} -e 's|"-O3"|""|' ${WRKSRC}/configure

post-install-EMACS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.for F in dinotrace.el sim-log.el
	${INSTALL_DATA} ${WRKSRC}/lisp/${F} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.endfor

.include <bsd.port.mk>
