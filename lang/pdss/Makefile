# New ports collection makefile for:	PDSS-KL1
# Date created:		07 Sep 2002
# Whom:			NINOMIYA Hideyuki <nin@Jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdss
PORTVERSION=	2.52.21
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.icot.or.jp/ifs/symbolic-proc/unix/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	nin@Jp.FreeBSD.org
COMMENT=	The KL1 programming environment on an ordinary UNIX system

EMACS_FILES=	kl1-mode.el pdss-init.e.el pdss-init.j.el \
		pdss-kl1cmp.el pdss-manual.el pdss.el

INSTALL_DIR=	${INSTALL} -d ${_SHROWNGRP} -m 0755

WRKSRC=		${WRKDIR}
MAKE_ENV+=	BSD_INSTALL_DIR="${INSTALL_DIR}"
SCRIPTS_ENV+=	BSD_INSTALL_DIR="${INSTALL_DIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

do-configure:
	@${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/Makefile
.for f in pdsscmp emulator/config.h emacs/pdss-init.el
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:" ${WRKSRC}/${f}
.endfor

post-build:
	@${CP} ${WRKSRC}/emacs/pdss-init.el ${WRKSRC}/emacs/pdss-init.e.el
	@${CP} ${WRKSRC}/emacs/pdss-init.el ${WRKSRC}/emacs/pdss-init.j.el
	@${REINPLACE_CMD} -e "s:%%DOCDIR%%:doc.e:" ${WRKSRC}/emacs/pdss-init.e.el
	@${REINPLACE_CMD} -e "s:%%DOCDIR%%:doc.j:" ${WRKSRC}/emacs/pdss-init.j.el

post-install:
	@${INSTALL_DIR} ${DATADIR}/emacs
.for f in ${EMACS_FILES}
	${INSTALL_DATA} ${WRKSRC}/emacs/${f} ${DATADIR}/emacs
.endfor

.include <bsd.port.post.mk>
