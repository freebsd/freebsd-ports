# New ports collection makefile for:	eb
# Version required:		2.3.7
# Date created:			20 Jan 1999
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

DISTNAME=	eb-2.3.7
PKGNAME=	ja-eb-2.3.7
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/
DISTFILES=	${EBFILES} ${APPENDIXFILES}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	eb-2.3.7+.diff

MAINTAINER=	takamune@avrl.mei.co.jp

EBFILES=	${DISTNAME}.tar.gz
APPENDIXFILES=	appendix/cencro-1.0.tar.gz \
		appendix/chujiten-2.3.tar.gz \
		appendix/chujiten2-2.0.tar.gz \
		appendix/chujiten6-2.3.tar.gz \
		appendix/colloc-2.0.tar.gz \
		appendix/crownfj-2.0.tar.gz \
		appendix/daihyakka-1.0.tar.gz \
		appendix/daijirin-2.0.tar.gz \
		appendix/dd75-2.0.tar.gz \
		appendix/genius-1.0.tar.gz \
		appendix/global-2.0.tar.gz \
		appendix/heritage-2.2.tar.gz \
		appendix/izumi-2.0.tar.gz \
		appendix/jitenban-2.4.tar.gz \
		appendix/jitenban97-2.1.tar.gz \
		appendix/kanjigen-2.0.tar.gz \
		appendix/kanjigen2-2.0.tar.gz \
		appendix/kojien-2.3.tar.gz \
		appendix/kojien2-2.0.tar.gz \
		appendix/kojien4-2.2.tar.gz \
		appendix/oxford-2.0.tar.gz \
		appendix/plus-2.0.tar.gz \
		appendix/readers-2.2.tar.gz \
		appendix/readers2-2.0.tar.gz
LISTFILES=	LIST LIST-ja

EXTRACT_ONLY=	${EBFILES}

DIST_SUBDIR=	eb
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-zlib

APPENDIXDIR=	${PREFIX}/share/eb/appendix

post-extract:
	cd ${WRKSRC} && ${RM} -rf zlib

post-install:
.for file in ${APPENDIXFILES}
	${TAR} -C ${APPENDIXDIR} -zxmf ${DISTDIR}/${DIST_SUBDIR}/${file}
.endfor
.for file in ${LISTFILES}
	${INSTALL_DATA} ${FILESDIR}/${file} ${APPENDIXDIR}
.endfor

.include <bsd.port.mk>
