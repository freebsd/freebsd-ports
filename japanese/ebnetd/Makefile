# New ports collection makefile for:	ndtpd
# Version required:		1.0.6
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id: Makefile,v 1.2 1998/04/22 12:32:10 asami Exp $
#

DISTNAME=	ndtpd-1.0.6
PKGNAME=	ja-ndtpd-1.0.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/appendix/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/appendix/old/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/old/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${APPENDIXFILES}

MAINTAINER=	m-kasahr@sra.co.jp

APPENDIXFILES=	chujiten-2.3.tar.gz \
		chujiten2-2.0.tar.gz \
		chujiten6-2.3.tar.gz \
		heritage-2.2.tar.gz \
		jitenban-2.4.tar.gz \
		jitenban97-2.1.tar.gz \
		kanjigen-2.0.tar.gz \
		kojien-2.3.tar.gz \
		kojien2-2.0.tar.gz \
		kojien4-2.2.tar.gz \
		readers-2.2.tar.gz \
		readers2-2.0.tar.gz

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DIST_SUBDIR=	ndtpd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --enable-ja-info
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"
.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	Maybe interactive at install stage
.endif

APPENDIXDIR=	share/ndtpd/appendix

post-install:
	for i in ${APPENDIXFILES}; do \
	    dir="`echo $$i | ${SED} 's/\.tar\.gz$$//'`"; \
	    ${RM} -rf ${PREFIX}/${APPENDIXDIR}/$$dir; \
	    (cd ${PREFIX}/${APPENDIXDIR} && ${EXTRACT_CMD} \
		${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/$$i ${EXTRACT_AFTER_ARGS}); \
	done
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in ndtpd.info ndtpd-ja.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
	@${SETENV} PKG_PREFIX=${PREFIX} IS_INTERACTIVE="${IS_INTERACTIVE}" \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

plist: extract
	${RM} -f ${PKGDIR}/PLIST
	${CAT} ${PKGDIR}/PLIST.top > ${PKGDIR}/PLIST
	for i in ${APPENDIXFILES}; do \
	    (cd ${WRKDIR}; \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/$$i \
		    ${EXTRACT_AFTER_ARGS}; \
		find "`echo $$i | ${SED} 's/\.tar\.gz$$//'`" -type f -print \
		    | ${SED} 's;^;${APPENDIXDIR}/;' >> ${PKGDIR}/PLIST); \
	done
	for i in ${APPENDIXFILES}; do \
	    (cd ${WRKDIR}; \
		find "`echo $$i | ${SED} 's/\.tar\.gz$$//'`" -type d \
		    -depth -print | ${SED} 's;^;@dirrm ${APPENDIXDIR}/;' \
		    >> ${PKGDIR}/PLIST); \
	done
	${CAT} ${PKGDIR}/PLIST.bot >> ${PKGDIR}/PLIST

.include <bsd.port.mk>
