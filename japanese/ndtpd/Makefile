# New ports collection makefile for:	ndtpd
# Version required:		2.0.3
# Date created:			4 Aug 1998
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id$
#

DISTNAME=	ndtpd-2.0.3
PKGNAME=	ja-ndtpd-2.0.3
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/appendix/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/appendix/old/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/old/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${APPENDIXFILES}
APPENDIXFILES=	chujiten-2.3.tar.gz \
		chujiten2-2.0.tar.gz \
		chujiten6-2.3.tar.gz \
		colloc-2.0.tar.gz \
		daijirin-2.0.tar.gz \
		global-2.0.tar.gz \
		heritage-2.2.tar.gz \
		izumi-2.0.tar.gz \
		jitenban-2.4.tar.gz \
		jitenban97-2.1.tar.gz \
		kanjigen-2.0.tar.gz \
		kojien-2.3.tar.gz \
		kojien2-2.0.tar.gz \
		kojien4-2.2.tar.gz \
		oxford-2.0.tar.gz \
		plus-2.0.tar.gz \
		readers-2.2.tar.gz \
		readers2-2.0.tar.gz

MAINTAINER=	m-kasahr@sra.co.jp

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DIST_SUBDIR=	ndtpd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --enable-ja-doc
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"
.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	Maybe interactive at install stage
.endif

APPENDIXDIR=	${PREFIX}/share/eb/appendix

post-install:
	for i in ${APPENDIXFILES}; do \
	    dir="`echo $$i | ${SED} 's/\.tar\.gz$$//'`"; \
	    ${RM} -rf ${APPENDIXDIR}/$$dir; \
	    (cd ${APPENDIXDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/$$i ${EXTRACT_AFTER_ARGS}); \
	done
	if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	${INSTALL_DATA} ${FILESDIR}/LIST ${APPENDIXDIR}/LIST
.for info in ndtpd ndtpd-ja ebinfo
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	@${SETENV} PKG_PREFIX=${PREFIX} IS_INTERACTIVE="${IS_INTERACTIVE}" \
	    ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
