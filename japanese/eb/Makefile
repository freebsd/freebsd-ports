# New ports collection makefile for:	eb
# Version required:		2.3.5
# Date created:			20 Jan 1999
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

DISTNAME=	eb-2.3.5
PKGNAME=	ja-eb-2.3.5
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/
DISTFILES=	${EBFILES} ${APPENDIXFILES}

MAINTAINER=	takamune@avrl.mei.co.jp

EBFILES=	${DISTNAME}.tar.gz
APPENDIXFILES=	cencro-1.0.tar.gz \
		chujiten-2.3.tar.gz \
		chujiten2-2.0.tar.gz \
		chujiten6-2.3.tar.gz \
		colloc-2.0.tar.gz \
		crownfj-2.0.tar.gz \
		daihyakka-1.0.tar.gz \
		daijirin-2.0.tar.gz \
		dd75-2.0.tar.gz \
		genius-1.0.tar.gz \
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
APPENDIXFILES:=	${APPENDIXFILES:S,^,appendix/,}
LISTFILES=	LIST LIST-ja

EXTRACT_ONLY=	${EBFILES}

DIST_SUBDIR=	eb
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-zlib
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

APPENDIXDIR=	${PREFIX}/share/eb/appendix

post-install:
.for file in ${APPENDIXFILES}
	${TAR} -C ${APPENDIXDIR} -zxmf ${DISTDIR}/${DIST_SUBDIR}/${file}
.endfor
.for file in ${LISTFILES}
	${INSTALL_DATA} ${FILESDIR}/${file} ${APPENDIXDIR}
.endfor

.include <bsd.port.mk>
