# New ports collection makefile for:	Mule-UCS for GNU Emacs 21
# Date created:		14 January 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	mule-ucs
PORTVERSION=	0.84
PORTREVISION=	1
CATEGORIES=	converters elisp
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/Mule-UCS/ \
		ftp://ftp.etl.go.jp/pub/mule/Mule-UCS/ \
		ftp://ftp.kddlabs.co.jp/Japan/m17n.org/mule/Mule-UCS/ \
		ftp://ftp.media.kyoto-u.ac.jp/mule/Mule-UCS/ \
		ftp://ftp.nihon-u.ac.jp/pub/text/m17n/mule/Mule-UCS/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	Mule-UCS-${PORTVERSION}

MAINTAINER?=	okazaki@FreeBSD.org

# This is a master port.
PORTCLASS?=	master

.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs21
.endif

MULEUCS_DESTDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mule-ucs
EMACS_ARGS=	-q --no-site-file -batch

do-build:
	cd ${WRKSRC}/lisp/big5conv && \
	    ${EMACS_CMD} ${EMACS_ARGS} -l big5-comp.el
	cd ${WRKSRC}/lisp/jisx0213 && \
	    ${EMACS_CMD} ${EMACS_ARGS} -l x0213-comp.el
	cd ${WRKSRC} && \
	    ${EMACS_CMD} ${EMACS_ARGS} -l mucs-comp.el

do-install:
	@${MKDIR} ${MULEUCS_DESTDIR}
	cd ${WRKSRC}/lisp; \
	for dir in . big5conv jisx0213 ; do \
		${MKDIR} ${MULEUCS_DESTDIR}/$${dir} ; \
		${INSTALL_DATA} $${dir}/*.el ${MULEUCS_DESTDIR}/$${dir} ; \
		${INSTALL_DATA} $${dir}/*.elc ${MULEUCS_DESTDIR}/$${dir} ; \
	done
	${MKDIR} ${MULEUCS_DESTDIR}/reldata
	cd ${WRKSRC}/lisp; \
		${INSTALL_DATA} reldata/*.el ${MULEUCS_DESTDIR}/reldata
	@${RM} ${MULEUCS_DESTDIR}/big5conv/big5-comp.el
	@${RM} ${MULEUCS_DESTDIR}/jisx0213/x0213-comp.el

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/lisp; \
	for i in ChangeLog MuleUni.txt README* ; do \
		${INSTALL_DATA} $${i} ${DOCSDIR} ; \
	done
	${INSTALL_DATA} ${WRKSRC}/lisp/big5conv/README \
			 ${DOCSDIR}/README.big5conv
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/ChangeLog \
			 ${DOCSDIR}/ChangeLog.jisx0213
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/readme.txt \
			 ${DOCSDIR}/README.jisx0213
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
