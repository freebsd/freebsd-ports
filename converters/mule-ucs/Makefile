# New ports collection makefile for:	Mule-UCS for GNU Emacs 20
# Date created:		14 January 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	mule-ucs
PORTVERSION=	0.83
CATEGORIES=	converters elisp
MASTER_SITES=	ftp://ftp.kddlabs.co.jp/Japan/m17n.org/mule/Mule-UCS/ \
		ftp://ftp.etl.go.jp/pub/mule/Mule-UCS/ \
		ftp://ftp.win.or.jp/pub/word/mule/Mule-UCS/ \
		ftp://ftp.m17n.org/pub/mule/Mule-UCS/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	Mule-UCS-${PORTVERSION}

MAINTAINER=	okazaki@FreeBSD.org

EMACS_PORT_NAME=	emacs20

ALL_TARGET=	elc

PLIST_SUB=	PORTDOCDIR=${PORTDOCDIR}
PORTDOCDIR=	share/doc/mule-ucs
MULEUCS_DESTDIR= ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mule-ucs
EMACS_ARGS=	-q --no-site-file -batch

do-build:
	cd ${WRKSRC} && \
	    ${EMACS_CMD} ${EMACS_ARGS} -l mucs-comp.el
	cd ${WRKSRC}/lisp/big5conv && \
	    ${EMACS_CMD} ${EMACS_ARGS} -l big5-comp.el
	cd ${WRKSRC}/lisp/jisx0213 && \
	    ${EMACS_CMD} ${EMACS_ARGS} -l x0213-comp.el

do-install:
	@${MKDIR} ${MULEUCS_DESTDIR}
	cd ${WRKSRC}/lisp; \
	for dir in . big5conv jisx0213 reldata ; do \
		${MKDIR} ${MULEUCS_DESTDIR}/$${dir} ; \
		${INSTALL_DATA} $${dir}/*.el* ${MULEUCS_DESTDIR}/$${dir} ; \
	done
	@${RM} ${MULEUCS_DESTDIR}/big5conv/big5-comp.el
	@${RM} ${MULEUCS_DESTDIR}/jisx0213/x0213-comp.el

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	cd ${WRKSRC}/lisp; \
	for i in ChangeLog MuleUni.txt README* ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${PORTDOCDIR} ; \
	done
	${INSTALL_DATA} ${WRKSRC}/lisp/big5conv/README \
			 ${PREFIX}/${PORTDOCDIR}/README.big5conv
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/ChangeLog \
			 ${PREFIX}/${PORTDOCDIR}/ChangeLog.jisx0213
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/readme.txt \
			 ${PREFIX}/${PORTDOCDIR}/README.jisx0213
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
