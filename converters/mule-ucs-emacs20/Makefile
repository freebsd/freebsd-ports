# New ports collection makefile for:	Mule-UCS for GNU Emacs 20
# Date created:		14 January 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	mule-ucs-${EMACS_PORT}
PORTVERSION=	0.74
CATEGORIES=	converters elisp
MASTER_SITES=	ftp://ftp.kddlabs.co.jp/Japan/m17n.org/mule/Mule-UCS/ \
		ftp://ftp.etl.go.jp/pub/mule/Mule-UCS/ \
		ftp://ftp.win.or.jp/pub/word/mule/Mule-UCS/ \
		ftp://ftp.center.osaka-u.ac.jp/mule/Mule-UCS/ \
		ftp://ftp.kreonet.re.kr/pub/tools/emacs/mule/Mule-UCS/ \
		ftp://ftp.m17n.org/pub/mule/Mule-UCS/
DISTNAME=	Mule-UCS-${PORTVERSION}

MAINTAINER=	okazaki@be.to

MULEUCSDOCDIR=	share/doc/mule-ucs

# emacs20
EMACS_PORT_NAME=	emacs20

# target name for make build
ALL_TARGET=	elc

EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT_NAME}
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT_NAME}
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		MULEUCSDOCDIR=${MULEUCSDOCDIR}
MAKE_FLAGS=	EMACS=${EMACS_CMD}

MULEUCS_DESTDIR= ${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp/mule-ucs
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
	@${MKDIR} ${PREFIX}/${MULEUCSDOCDIR}
	cd ${WRKSRC}/lisp; \
	for i in ChangeLog MuleUni.txt README* ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${MULEUCSDOCDIR}/ ; \
	done
	${INSTALL_DATA} ${WRKSRC}/lisp/big5conv/README \
			 ${PREFIX}/${MULEUCSDOCDIR}/README.big5conv
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/ChangeLog \
			 ${PREFIX}/${MULEUCSDOCDIR}/ChangeLog.jisx0213
	${INSTALL_DATA} ${WRKSRC}/lisp/jisx0213/readme.txt \
			 ${PREFIX}/${MULEUCSDOCDIR}/README.jisx0213
.endif

.include <bsd.port.mk>
