# New ports collection makefile for:	eb
# Version required:		2.2
# Date created:			20 Jan 1999
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id: Makefile,v 1.5 1998/10/16 04:32:50 jseger Exp $
#

DISTNAME=	eb-2.2
PKGNAME=	ja-eb-2.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/appendix/ \
		ftp://ftp.sra.co.jp/pub/misc/eb/appendix/old/ \
		ftp://ftp.sra.co.jp/pub/misc/eb/ \
		ftp://ftp.sra.co.jp/pub/misc/eb/old/
DISTFILES=	${EBFILES} ${APPENDIXFILES}

MAINTAINER=	m-kasahr@sra.co.jp

EBFILES=	${DISTNAME}.tar.gz
APPENDIXFILES=	chujiten-2.3.tar.gz \
		chujiten2-2.0.tar.gz \
		chujiten6-2.3.tar.gz \
		colloc-2.0.tar.gz \
		crownfj-2.0.tar.gz \
		daijirin-2.0.tar.gz \
		dd75-2.0.tar.gz \
		global-2.0.tar.gz \
		heritage-2.2.tar.gz \
		izumi-2.0.tar.gz \
		jitenban-2.4.tar.gz \
		jitenban97-2.1.tar.gz \
		kanjigen-2.0.tar.gz \
		kanjigen2-2.0.tar.gz \
		kojien-2.3.tar.gz \
		kojien2-2.0.tar.gz \
		kojien4-2.2.tar.gz \
		oxford-2.0.tar.gz \
		plus-2.0.tar.gz \
		readers-2.2.tar.gz \
		readers2-2.0.tar.gz

EXTRACT_ONLY=	${EBFILES}

DIST_SUBDIR=	eb
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

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
	${INSTALL_DATA} ${FILESDIR}/LIST-ja ${APPENDIXDIR}/LIST-ja
.for info in eb ebinfo ebfont ebrefile ebzip
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
