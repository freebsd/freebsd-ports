# New ports collection makefile for:   makejvf-fkr-1.0
# Version required:    1.0
# Date created:        6 Oct 1999
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

DISTNAME=	makejvf-1.0-fkr
PKGNAME=	ja-makejvf-fkr-1.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.tooyoo.l.u-tokyo.ac.jp/pub/TeX/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		standard${EXTRACT_SUFX} nmin-ngoth${EXTRACT_SUFX} \
		jis${EXTRACT_SUFX} morisawa${EXTRACT_SUFX}

MAINTAINER=	inagaki@tg.rim.or.jp

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DIST_SUBDIR=    makejvf
INSTALL_TARGET=	install-all
BINARIES=	makejvf makejvfh makejvfk
MAKEJVFDIR=	${PREFIX}/share/fonts/makejvf
PTEXTFM=	standard nmin-ngoth jis morisawa

DOCS=	README.1st README.txt test1.tex test2.tex kuten2jis jy1mch.fd

post-extract:
	@for i in ${PTEXTFM} ; do \
		${TAR} -C ${WRKDIR}/ -zxf ${DISTDIR}/${DIST_SUBDIR}/$$i${EXTRACT_SUFX} ; \
	done

post-install:
	@${MKDIR} ${MAKEJVFDIR}
	@for i in ${PTEXTFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/$$i/$$i.map \
			${MAKEJVFDIR}/ ; \
	done

	@${MKDIR} ${MAKEJVFDIR}/tfm/ptex
	@for i in ${PTEXTFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/$$i/tfm/ptex/* \
			${MAKEJVFDIR}/tfm/ptex/ ; \
	done

	@${MKDIR} ${MAKEJVFDIR}/tfm/dvips
	@for i in ${PTEXTFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/$$i/tfm/dvips/* \
			${MAKEJVFDIR}/tfm/dvips/ ; \
	done

	@${MKDIR} ${MAKEJVFDIR}/vf
	@for i in ${PTEXTFM} ; do \
		${INSTALL_DATA} ${WRKDIR}/$$i/vf/* \
			${MAKEJVFDIR}/vf/ ; \
	done

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/makejvf-fkr
	@for i in ${DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/makejvf-fkr ; \
	done
.endif

.include <bsd.port.mk>
