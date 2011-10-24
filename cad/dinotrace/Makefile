# New ports collection makefile for:	dinotrace
# Date created:		July 05, 2004
# Whom:			Joachim Strombergson <watchman@ludd.ltu.se>
#
# $FreeBSD$
#

PORTNAME=	dinotrace
DISTVERSION=	9.3f
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.org/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical signal trace waveform viewer

OPTIONS=	EMACS "Install Emacs supplimentary files" on

GNU_CONFIGURE=	yes
USE_MOTIF=	yes
USE_PERL5_BUILD=	yes
USE_XORG=	x11 sm ice xmu xt
USE_GMAKE=	yes

INFO=		dinotrace

VERILOGEL_FILE=	${LOCALBASE}/share/verilog-mode.el/verilog-mode.el
ELFILES=	dinotrace.el sim-log.el
EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

.include <bsd.port.pre.mk>
.if !defined(WITHOUT_EMACS)
RUN_DEPENDS+=	${VERILOGEL_FILE}:${PORTSDIR}/cad/verilog-mode.el
PLIST_SUB+=	EMACS=""
.else
PLIST_SUB+=	EMACS="@comment "
.endif

post-install:
.if !defined(WITHOUT_EMACS)
	${MKDIR} ${DATADIR}/
	${MKDIR} ${XEMACSLISPDIR}
. for FILE in ${ELFILES}
	${INSTALL_DATA} ${WRKSRC}/lisp/${FILE} ${DATADIR}/
	${LN} -sf ${DATADIR}/${FILE} ${EMACSLISPDIR}/${FILE}
	${LN} -sf ${DATADIR}/${FILE} ${XEMACSLISPDIR}/${FILE}
. endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
