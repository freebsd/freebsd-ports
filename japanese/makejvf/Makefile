# New ports collection makefile for:   makejvf-fkr-1.0
# Date created:        6 Oct 1999
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	makejvf-fkr
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.tooyoo.l.u-tokyo.ac.jp/pub/TeX/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS
DISTNAME=	makejvf-${PORTVERSION}-fkr
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		standard${EXTRACT_SUFX} nmin-ngoth${EXTRACT_SUFX} \
		jis${EXTRACT_SUFX} morisawa${EXTRACT_SUFX}

MAINTAINER=	inagaki@tg.rim.or.jp

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DIST_SUBDIR=    makejvf
INSTALL_TARGET=	install-all
BINARIES=	makejvf makejvfh makejvfk
TEXMF=		${PREFIX}/share/texmf
MAKEJVF_DIR=	${PREFIX}/share/fonts/makejvf
MAP_DIR=	${TEXMF}/dvips/makejvf
PTEX_TFM_DIR=	${TEXMF}/fonts/tfm/makejvf
DVIPS_TFM_DIR=	${TEXMF}/fonts/tfm/makejvf
DVIPS_VF_DIR=	${TEXMF}/fonts/vf/makejvf
PTEX_TFM=	standard nmin-ngoth jis morisawa

DOCS=		README.1st README.txt test1.tex test2.tex kuten2jis jy1mch.fd

post-extract:
	@for i in ${PTEX_TFM} ; do \
		${TAR} -C ${WRKDIR}/ -zxf ${DISTDIR}/${DIST_SUBDIR}/$$i${EXTRACT_SUFX} ; \
	done

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${MAP_DIR}
	@for i in ${PTEX_TFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/$$i/$$i.map \
			${MAP_DIR}/ ; \
	done

	@${MKDIR} ${PTEX_TFM_DIR}/ptex
	@for i in ${PTEX_TFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/$$i/tfm/ptex/* \
			${PTEX_TFM_DIR}/ptex/ ; \
	done

	@${MKDIR} ${DVIPS_TFM_DIR}/dvips
	@for i in ${PTEX_TFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/$$i/tfm/dvips/* \
			${DVIPS_TFM_DIR}/dvips/ ; \
	done

	@${MKDIR} ${DVIPS_VF_DIR}
	@for i in ${PTEX_TFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/$$i/vf/* \
			${DVIPS_VF_DIR}/ ; \
	done

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/makejvf-fkr
	@for i in ${DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/makejvf-fkr ; \
	done
.endif

.if exists(${PREFIX}/bin/mktexlsr)
	@${PREFIX}/bin/mktexlsr
.endif

.include <bsd.port.post.mk>
